#!/usr/bin/env python3
"""Bounds-checked educational parser for the EduReversing relocation fixture."""
from pathlib import Path
import struct,sys

H={0x3F3:"HUNK_HEADER",0x3E9:"HUNK_CODE",0x3EA:"HUNK_DATA",0x3EB:"HUNK_BSS",
   0x3EC:"HUNK_RELOC32",0x3F0:"HUNK_SYMBOL",0x3F2:"HUNK_END"}

class R:
    def __init__(self,b): self.b=b; self.o=0
    def u(self):
        if self.o+4>len(self.b): raise ValueError("truncated")
        x=struct.unpack_from(">I",self.b,self.o)[0]; self.o+=4; return x
    def take(self,n):
        if self.o+n>len(self.b): raise ValueError("truncated")
        x=self.b[self.o:self.o+n]; self.o+=n; return x

def parse(p):
    r=R(p.read_bytes())
    if r.u()!=0x3F3 or r.u()!=0: raise ValueError("bad header")
    n,first,last=r.u(),r.u(),r.u()
    sizes=[r.u()&0x3fffffff for _ in range(last-first+1)]
    print(f"HUNK_HEADER table={n} first={first} last={last} sizes={sizes}")
    current=-1
    while r.o<len(r.b):
        k=r.u()
        if k==0x3E9 or k==0x3EA:
            current+=1; longs=r.u(); data=r.take(longs*4)
            print(f"{H[k]} hunk={current} longs={longs} bytes={data.hex()}")
        elif k==0x3EB:
            current+=1; print(f"HUNK_BSS hunk={current} longs={r.u()}")
        elif k==0x3EC:
            while True:
                count=r.u()
                if count==0: break
                target=r.u(); offs=[r.u() for _ in range(count)]
                print(f"HUNK_RELOC32 source={current} target={target} offsets={offs}")
        elif k==0x3F0:
            while True:
                longs=r.u()
                if longs==0: break
                raw=r.take(longs*4); value=r.u()
                nm=raw.rstrip(b"\0").decode("ascii")
                print(f"HUNK_SYMBOL hunk={current} name={nm} value={value}")
        elif k==0x3F2:
            print(f"HUNK_END hunk={current}")
        else: raise ValueError(f"unsupported record 0x{k:08x}")
def main():
    try: parse(Path(sys.argv[1]))
    except (IndexError,OSError,ValueError) as e:
        print(f"error: {e}",file=sys.stderr); return 1
    return 0
if __name__=="__main__": raise SystemExit(main())

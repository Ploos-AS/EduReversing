# Protocol/message recovery template

## Sample provenance

Record the exact fixture hash, command line and environment.

## Byte map

| Offset | Width | Candidate field | Byte order | Evidence | Confidence |
|---|---:|---|---|---|---|

## Validation stages

List observed validation stages in execution order, including the evidence for each stage and its failure class.

## Length relationships

Write explicit equations, for example `total = header + payload + trailer`, only after demonstrating them with multiple inputs.

## Integrity mechanism

Document covered bytes, initial state, update operation, output width and stored byte order.

## Unknowns

Preserve unexplained bytes or behavior as unknown rather than forcing a semantic name.

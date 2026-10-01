# Evidence ledger

Use this ledger for advanced investigations.

| Finding | Direct observation | Interpretation | Confidence | Competing explanation | Cross-check |
|---|---|---|---|---|---|
| Example | instruction/data/runtime fact | what it likely means | confirmed / strong / tentative / unknown | plausible alternative | second independent source of evidence |

## Confidence language

- **Confirmed** — directly demonstrated by reproducible evidence.
- **Strongly supported** — multiple observations agree; no meaningful contradictory evidence.
- **Tentative** — plausible interpretation with incomplete support.
- **Unknown** — evidence does not currently justify a conclusion.

Confidence is attached to a finding, not to the analyst.

## Evidence hierarchy

Prefer conclusions supported by independent forms of evidence: control flow plus data references, static prediction plus runtime observation, or two program versions showing the same structural relationship.

Strings, imports, decompiler output and names are clues. None alone proves behavior.

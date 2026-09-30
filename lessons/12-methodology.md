# Lesson 12 — A disciplined reversing methodology

## Mission

Replace random tool exploration with a repeatable investigation process.

## The investigation loop

Use this loop:

1. preserve and identify the artifact;
2. collect cheap metadata;
3. form initial hypotheses;
4. map code and data;
5. name only what evidence supports;
6. identify unanswered questions;
7. choose static or dynamic evidence to answer them;
8. revise hypotheses;
9. document conclusions and uncertainty.

## Evidence ledger

Maintain a table:

| ID | Observation | Source | Interpretation | Confidence |
|---|---|---|---|---|

Keep observation and interpretation separate.

Example:

- Observation: a call target receives `rdi` pointing at a decimal string.
- Interpretation: the function may parse a number.

The second statement is not automatically a fact.

## Function map

Create a compact map:

| Function | Callers | Callees | Inputs | Outputs | Current role |
|---|---|---|---|---|---|

Start with neutral names. Refine them as evidence accumulates.

## Question-driven analysis

Bad workflow:

> scroll through disassembly until something looks interesting.

Better workflow:

> Which function decides between output A and B?

That question suggests concrete next actions: locate output strings, inspect XREFs, identify callers, map the controlling branch.

## Stop conditions

An investigation can expand forever. Define what must be known.

For a course case, stop when you can support:

- major inputs;
- major outputs;
- principal transformations;
- important decisions;
- external interactions;
- unresolved uncertainty relevant to the question.

## Deliverable

Use the template in `docs/ANALYSIS-TEMPLATE.md` for later investigations.

## Principle

**Good reversing is question-driven evidence management.**

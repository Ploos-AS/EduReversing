# Lesson 16 — Configuration extraction

## Mission

Recover structured information from an encoded, benign configuration blob.

## Why configuration matters

Real-world defensive analysis often needs answers such as:

- which identifiers are embedded?
- which endpoints are referenced?
- which feature flags exist?
- which campaign/version marker is present?

This lab teaches the extraction workflow without using a malicious specimen.

## Fixture format

The course fixture contains a small byte array transformed with a reversible educational encoding.

Your task:

1. locate the blob;
2. determine its length;
3. identify the decoding loop;
4. reconstruct the transformation;
5. decode it independently;
6. parse the resulting key/value text.

Do not begin by reading the fixture source.

## Validate independently

You may use a tiny throwaway script or manual calculation to validate your reconstructed transformation. The important evidence remains the binary's implementation.

## Deliverable

Document:

- blob location;
- transformation;
- decoded fields;
- code references;
- confidence;
- reproduction steps.

## Principle

**Config extraction is a data-reconstruction problem: locate, transform, parse, validate.**

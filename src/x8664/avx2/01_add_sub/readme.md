[Checkout this amazing cheatsheet.](https://db.in.tum.de/~finis/x86%20intrinsics%20cheat%20sheet%20v1.0.pdf)

# Simple Operations

## With Saturation

### `_mm256_adds_ps`

Add two packs of single-precision floating-point values with saturation.
Other variants: `_mm256_adds_epi32`, `_mm256_adds_epi64`, `_mm256_adds_pd`.

### `_mm256_subs_ps`

Subtract two packs of single-precision floating-point values with saturation.
Other variants: `_mm256_subs_epi32`, `_mm256_subs_epi64`, `_mm256_subs_pd`.

## Without Saturation

### `_mm256_add_ps`

Add two packs of single-precision floating-point values.
Other variants: `_mm256_add_epi32`, `_mm256_add_epi64`, `_mm256_add_pd`.

### `_mm256_sub_ps`

Subtract two packs of single-precision floating-point values.
Other variants: `_mm256_sub_epi32`, `_mm256_sub_epi64`, `_mm256_sub_pd`.  
**Example: `_mm256_sub_epi64`** Subtracts 64-bit integers from corresponding elements of two 256-bit vectors of [4 x i64]. Returns the
lower 64 bits of each difference in the corresponding element of the [4 x i64] result (overflow is ignored).


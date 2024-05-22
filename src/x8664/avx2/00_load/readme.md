[Checkout this amazing cheatsheet.](https://db.in.tum.de/~finis/x86%20intrinsics%20cheat%20sheet%20v1.0.pdf)

# Initializing a pack without loading from memory

## `_mm256_set1_ps`

Init a pack with a single scalar float value (broadcast).
Other variants: `_mm256_set1_epi32`, `_mm256_set1_epi64x`, `_mm256_set1_pd`.

## `_mm256_set_ps`

Init a pack with multiple scalar values.
Other variants: `_mm256_set_epi32`, `_mm256_set_epi64x`, `_mm256_set_pd`.

## `_mm256_setr_ps`

Init a pack with multiple scalar values in reverse order.
Other variants: `_mm256_setr_epi32`, `_mm256_setr_epi64x`, `_mm256_setr_pd`.

## `__mm256_insert_epi32`

**WARNING**: This intrinsic does not support float32 or 64.
Insert a scalar value into a pack at a specific position.
Other variants: `_mm256_insert_epi32`, `_mm256_insert_epi64x`, `_mm256_insert_pd`.

# Initializing a pack by loading from memory

## With Aligned Memory

### `_mm256_load_ps`

Loads 8 single-precision floating point values from a 32-byte aligned memory location pointed to by __p into a vector
of [8 x float].
Other variants: `_mm256_load_epi32`, `_mm256_load_epi64x`, `_mm256_load_pd`.

###  

## With Unaligned Memory

### `_mm256_loadu_ps`

Loads 8 single-precision floating point values from an unaligned memory location pointed to by \a __p into a vector
of [8 x float].
Other variants: `_mm256_loadu_epi32`, `_mm256_loadu_epi64x`, `_mm256_loadu_pd`, `_mm256_loadu_si256`.


**WARNING:** In AVX2 intrinsics, epi stands for "Extended Packed Integer". This is used to denote functions that operate
on packed integer vectors. For example, _mm256_loadu_epi32 loads 8 32-bit integers into a 256-bit integer vector. On the
other hand, si256 stands for "Scalar Integer 256 bits". This is used to denote functions that operate on one 256-bit
integer. For example, _mm256_loadu_si256 loads a 256-bit integer from an unaligned memory location. The main difference
between epi and si256 is the type of data they operate on. epi functions operate on packed integer vectors, while si256
functions operate on single 256-bit integers.

### `_mm256_loadu2_m128`

Loads two 128-bit floating-point vectors of [4 x float] from unaligned memory locations and constructs a 256-bit
floating-point vector of [8 x float] by concatenating the two 128-bit vectors.

There are many others, see the cheatsheet for more information.


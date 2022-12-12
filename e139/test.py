#!/usr/bin/env python3
import random

n = 10**3
random.seed(123)

print(n)
for _ in range(n):
    x = random.randint(1, 10**7)
    y = random.randint(1, 10**7)
    print(f"{x} {y}")

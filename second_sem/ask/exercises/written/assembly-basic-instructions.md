## State of the machine

| Address | Value |
|---------|-------|
| 0x100   | 0xFF  |
| 0x108   | 0AB   |
| 0x110   | 0x13  |
| 0x118   | 0x11  |

| Register | Value |
|---------|-------|
| %rax     | 0x100 |
| %rcx     | 1 |
| %rdx     | 3 |

### Evaluation of source operands with abovedescribed state of the machine
```
1. %rax = 0x100
2. 0x110 = 0x13
3. $0x108 = 0x108
4. (%rax) = 0xFF
5. 8(%rax) = 0xFF + 8 = 0x107
6. 21(%rax, %rdx) = 0x100 + 3 + 21 = 0x118
7. 0xFC(,%rcx. 4) = 0xFC + 4 * 1 = 0x100
8. (%rax, %rdx, 8) = 0x100 + 24 = 0x118
9. 265(%rcx, %rdx, 2) = 265 + 3 * 2 = 0x10F
```

### Evaluation of operations with abovedescribed state of the machine 
```
1. addq %rcx,(%rax) = 0xFF + 1 = 0x100 (saved @ 0x100)
2. subq 16(%rax),%rdx = 0xFF + 16 - 3 = 0x10C (saved @ 0x103)
3. shrq $4,%rax = 0x100 >> 4 = 0x8 (saved %rax)
4. incq 16(%rax) = (0x10F) + 1 (saved @ 0x10F) // Will it? it is not a register
5. decq %rcx = 1 - 1 = 0 (saved @ %rcx) 
6. imulq 8(%rax) = 0xAB * 0x100 = 0xAB00 (saved @ 0x108)
7. leaq 7(%rcx,%rcx,8),%rdx = 7 + 9 = 16 (saved @ %rdx)
8. leaq 0xA(,%rdx,4),%rdx = 0xA + 12 = 16 (saved @ %rdx)
```
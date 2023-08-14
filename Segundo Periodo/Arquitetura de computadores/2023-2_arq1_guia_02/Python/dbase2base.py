def dbase2base(base1, base2, x):
    if not (2 <= base1 <= 16 and 2 <= base2 <= 16):
        raise ValueError("As bases devem estar entre 2 e 16")

    if isinstance(x, str):
        num = int(x, base1)
    elif isinstance(x, int):
        num = x
    else:
        raise ValueError("O número deve ser uma string ou um inteiro")

    if num == 0:
        return '0'

    digits = '0123456789ABCDEF'
    result = ''
    while num > 0:
        digit = num % base2
        result = digits[digit] + result
        num //= base2

    return result


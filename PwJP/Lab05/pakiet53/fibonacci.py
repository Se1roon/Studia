def fib_iter(n: int):
    if n <= 0:
        return 1

    current = 1
    previous = 1
    z = 1

    i = 1
    while i != n:
        z = current
        current += previous
        previous = z
        i += 1
   
    return current


def fib_rek(n: int):
    if n <= 1:
        return 1;

    return fib_rek(n - 1) + fib_rek(n - 2);


def rebase(input_base, digits, output_base):
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if output_base < 2:
        raise ValueError("output base must be >= 2")
    decimal_num = 0
    for index, digit in enumerate(reversed(digits)):
        if digit < 0 or digit >= input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")
        decimal_num += digit * input_base ** index
    if decimal_num == 0 or digits == []:
        return [0]
    output_digits = []
    while decimal_num > 0:
        output_digits.insert(0, decimal_num % output_base)
        decimal_num = decimal_num // output_base
    return output_digits
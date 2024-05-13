def test(input: str) -> int:
    somma = 0
    contatore = 0

    for letter in input:
        if letter.isdigit():
            somma += int(letter)
            contatore += 1

    return somma


print(test("3dh5si8skg91g91"))
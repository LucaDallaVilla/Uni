import random
import time

def main():
    used_nums = []
    cond = True
    i = 0
    my_input = int(input("Scegli bene un numero tra 0 e 100 compresi: "))

    if (my_input > 100 or my_input < 0):
        print("A cojone!")
        return

    while cond:
        number = random.randint(1, 100)
        while number in used_nums:
            number = random.randint(1, 100)
        
        used_nums.append(number)
        if (number == my_input):
            print(f"Numero {number} indovinato.")
            cond = False
        else:
            i += 1
            print(f"Niente da fare! Io ho scelto il {number}. [{used_nums.count(number) > 1}]")
            time.sleep(0.5)
    
    print(f"Tentativi: {i}.")


if __name__ == "__main__":
    run = True
    while run:
        main()
        if (input("Continuare? [S/n]: ").lower() != "s"):
            run = False
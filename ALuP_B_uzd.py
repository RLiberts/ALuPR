def apgriezts(x):
    ap=0
    if x<0:
        x=-x
    while x>0:
        ap=ap*10+x%10
        x//=10
    return ap

def simetrija(x):
    if x<0:
        x=-x
    return x==apgriezts(x)

while True:
    #Pieņem, ka vislaik tiks ievadīti veseli skaitļi.
    n = int(input("Ievadi intervāla sākuma punktu, n (vesels skaitlis):"))
    m = int(input("Ievadi intervāla beigu punktu, m (vesels skaitlis):"))
    sim = False
    # Pārbauda, vai ievadītās vērtības ir loģiski pieļaujamas
    if n > m:
        print("Sākuma intervāla vērtībai(n) jābūt mazākai par beigu intervāla vērtību(m)")
    else:
        for i in range(n, m+1):
            if simetrija(i) and simetrija(i*i):
                sim=True
                print(f"{i} ir simetrisks skaitlis, tā kvadrāts ir {i*i},kas arī ir simetrisks skaitlis")
        if sim==False:
            print("Nav tāda skaitļa intervālā, kurš pats būtu simetrisks un arī tā kvadrāts.")
        # Atkārtotas izpildes izvēle
    turpinat = input("Veikt atkārtoti izvēli? (1/0)").lower().strip()
    if turpinat == "1":
        continue
    elif turpinat == "0":
        print("Beidz darbu.")
        exit()


"""
Ievade                        Programmas vēlamā reakcija
n=1, m=4                      1 ir simetrisks skaitlis, tā kvadrāts ir 1,kas arī ir simetrisks skaitlis
                              2 ir simetrisks skaitlis, tā kvadrāts ir 4,kas arī ir simetrisks skaitlis
                              3 ir simetrisks skaitlis, tā kvadrāts ir 9,kas arī ir simetrisks skaitlis

n=-55, m=55                   -22 ir simetrisks skaitlis, tā kvadrāts ir 484,kas arī ir simetrisks skaitlis
                              -11 ir simetrisks skaitlis, tā kvadrāts ir 121,kas arī ir simetrisks skaitlis
                              -3 ir simetrisks skaitlis, tā kvadrāts ir 9,kas arī ir simetrisks skaitlis
                              -2 ir simetrisks skaitlis, tā kvadrāts ir 4,kas arī ir simetrisks skaitlis
                              -1 ir simetrisks skaitlis, tā kvadrāts ir 1,kas arī ir simetrisks skaitlis
                              0 ir simetrisks skaitlis, tā kvadrāts ir 0,kas arī ir simetrisks skaitlis
                              1 ir simetrisks skaitlis, tā kvadrāts ir 1,kas arī ir simetrisks skaitlis
                              2 ir simetrisks skaitlis, tā kvadrāts ir 4,kas arī ir simetrisks skaitlis
                              3 ir simetrisks skaitlis, tā kvadrāts ir 9,kas arī ir simetrisks skaitlis
                              11 ir simetrisks skaitlis, tā kvadrāts ir 121,kas arī ir simetrisks skaitlis
                              22 ir simetrisks skaitlis, tā kvadrāts ir 484,kas arī ir simetrisks skaitlis

n=14, m=16                    Nav tāda skaitļa intervālā, kurš pats būtu simetrisks un arī tā kvadrāts
"""
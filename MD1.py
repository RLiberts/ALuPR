"""
Ričards Nils Liberts, rl25036
A21. Doti 3 naturāli skaitļi m, n un k. 
Izdrukāt tos skaitļus, kuri atrodas intervālā [m,n] un kuri dalās ar k bez atlikuma.
Programma izveidota: 29.09.2025.
"""

while True: # Galvenais cikls, kas ļauj atkārtotu izpildi.
    # Pieņem, ka vislaik tiks ievadīti veseli skaitļi.
    m = int(input("Ievadi intervāla sākuma punktu (vesels skaitlis >= 1):"))
    n = int(input("Ievadi intervāla beigu punktu (vesels skaitlis >= 1):"))
    k = int(input("Ievadi dalītāju (vesels skaitlis > 0):"))

    # Pārbauda, vai ievadītās vērtības ir loģiski pieļaujamas
    if m > n:
        print("Sākuma intervāla vērtībai(M) jābūt mazākai par beigu intervāla vērtību(N)")
    else:
        # Galvenais bloks, kur iet cauri visiem intervāla skaitļiem un pārbauda, vai tie dalās ar lietotāja norādīto dalītāju.
        print("Skaitļi, kuri atrodas intervālā", m, "-", n, "un dalās ar", k, ":")
        num = False # Deklerē mainīgo, kura vērtība reflektē vai vispār ir atrasts kāds skaitlis, kas dalās ar ievadīto dalītāju.
        for i in range(m, n + 1): # cikls, lai meklētu skaitļus i intervālā [m,n], kuri dalās ar k bez atlikuma.
            if i % k == 0: # šī darbība pārbauda nepieciešama, lai pārbaudītu, vai skaitlis i dalās ar k bez atlikuma.
                print(i)
                num = True # Atrodot vismaz vienu tādu skaitli, kas dalās ar k, mainīgā vērtībai tiek piešķirts True.
        if not num: # Ja netiek atrasts tāds skaitlis, kas dalās ar k, mainīgā vērtība nemainīgi paliek False, kas ļauj izdrukāt paziņojumu, ka nav tāds skaitlis, kas dalās ar k
            print("Nav atrasts neviens skaitlis intervālā, kas dalās ar", k)

    # Atkārtotas izpildes izvēle
    turpinat = input("Veikt atkārtoti izvēli? (j/n)").lower().strip()
    if turpinat == "j":
        continue
    elif turpinat == "n":
        print("Beidz darbu.")
        exit()
   
"""
            Testa plāns
Ievade                      Programmas vēlamā reakcija
m=1, n=18, k=3              3, 6, 9, 12, 15, 18
m=18, n=1, k=3              Sākuma intervāla vērtībai(M) jābūt mazākai par beigu intervāla vērtību(N)
m=1, n=5, k=10              Nav atrasts neviens skaitlis intervālā, kas dalās ar 10

"""

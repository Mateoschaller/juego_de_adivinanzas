print("bienvenidos a un juego de adivinanzas de numeros")
print("a continuacion le vamos a pedir 3 numeros que debera ingresar para la adivinanza de nunmeros. un minimo, un maximo y la cantidad de intentos que desea realizar")
numeroMinimo = int(input("ingrese el numero minimo: "))
numeroMaximo = int(input("ingrese el numero maximo: "))
numeroDeIntentos = int(input("ingrese el numero de intentos que desea realizar: "))

if numeroMinimo > numeroMaximo:
    print("disculpa estas ingresando un numero mas grande en el minimo que en el maximo")

arr = []
numerosDeIntentosRestantes = numeroDeIntentos
from random import randint
numeroRandom = randint(numeroMinimo,numeroMaximo)    
contador = 0
while contador < numeroDeIntentos:
    contador += 1
    numerosDeIntentosRestantes -= 1    
    numeroAdivinado = int(input("intente adivinar el numero: "))
    
    if numeroAdivinado not in arr: arr.append(numeroAdivinado)
    else: print("el numero ya fue ingresado anteriormente")    
    
    if numeroRandom == numeroAdivinado:
        print(f'BIEN acertaste el numero en {contador} intentos')
        arr.sort()        
        print(arr) 
        break
    elif numeroRandom > numeroAdivinado:
        if numerosDeIntentosRestantes != 0:
            print(f'el numero es mayor, sigue intentando, vas {contador} intentos, y te quedan {numerosDeIntentosRestantes} intentos')
            arr.sort()         
            print(arr)
        else:print("te quedaste sin intentos")
    elif numeroRandom < numeroAdivinado:
        if numerosDeIntentosRestantes != 0:
            print(f'el numero es menor, sigue intentando vas {contador} intentos, y te quedan {numerosDeIntentosRestantes} intentos')
            arr.sort()         
            print(arr)
        else:print("te quedaste sin intentos")
                   
        
               
        
                  
        
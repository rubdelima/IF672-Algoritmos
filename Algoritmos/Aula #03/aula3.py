def merge(lis1, tam_lista1, list2, tam_lista2):
    contador1 = 0
    contador2= 0
    lista_aux =[]
    while True:
        if contador1 == tam_lista1:
            while True:
                lista_aux.append(list2[contador2])
                contador2 += 1
                if contador2 == tam_lista2:
                    return lista_aux
                
        if contador2 == tam_lista2:
            while True:
                lista_aux.append(lis1[contador1])
                contador1 += 1
                if contador1 == tam_lista1:
                    return lista_aux
                
        if lis1[contador1] < list2[contador2]:
            lista_aux.append(lis1[contador1])
            contador1 += 1
        else:
            lista_aux.append(list2[contador2])
            contador2 += 1

            

def mergesort(lista, tam_lista):
    if tam_lista == 1:
        return lista
    if tam_lista %2 == 0:
        return merge(mergesort(lista[:(tam_lista//2)],tam_lista//2),tam_lista//2, mergesort(lista[(tam_lista//2):], (tam_lista//2)), tam_lista//2)
    else:
        return merge(mergesort(lista[:(tam_lista//2)],tam_lista//2), tam_lista//2, mergesort(lista[(tam_lista//2):], 1+(tam_lista//2)), 1+tam_lista//2)


def convert_lista(lista):
    for i in range(len(lista)):
        lista[i] = int(lista[i])
    return lista
    
    
lista = [3,45,65,9,8,114,2,1,0,3,3,99,4,3,3,45,6,47,9]
lista = mergesort(lista, len(lista))
print(*lista)
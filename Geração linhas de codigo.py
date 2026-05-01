while True:
    q = int(input('Quantidade de linhas: '))
    local = input('Local dos aquivos: ')
    action = input('Nome dos aquivos: ')

    for c in range(0,q):
        print(f'    frame   {local}{action}{c:02}.gif')

    print()
    Q =input('quer gerar outro? [S/N]').upper()
    if Q == 'N':
        break
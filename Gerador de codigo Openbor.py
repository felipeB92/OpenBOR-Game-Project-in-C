def eint(n):
    while True:
        b = input(f'{n}')
        try:
            b = int(b)
            return b
        except (ValueError, TypeError):
            print(f'\033[1;31mo valor {b} é invalido\033[m')

def SouN(n):
    while True:
        b= input(n).upper()
        if b == 'S':
            return 'S'
        if b == 'N':
            return 'N'


def exibir_cabecalho():
    largura = 50
    titulo = "CRIADOR DE CODIGOS PERSONAGENS"
    autor = "Por Felipe B. Silva"

    print("┌" + "─" * (largura - 2) + "┐")
    print("│" + titulo.center(largura - 2) + "│")
    print("│" + autor.center(largura - 2) + "│")
    print("└" + "─" * (largura - 2) + "┘")


jogador = ['idle','Attack1','Attack2','Attack3','walk','run','runattack','grabattack','grabattack2','special','special2']
inimigo = ['idle','Attack1','walk',]
Boss = ['Attack1','Attack2','Attack3','idle','walk','special','special2']
tipo = 0
pasta = 'data'
exibir_cabecalho()
print('[1]jogador\n[2]inimigo\n[3]Boss')
while tipo != 1 and tipo != 2 and tipo != 3:
    tipo = eint('Qual o tipo Personagen: ')

if tipo == 1:
    pasta = 'player'
    lista = jogador
if tipo == 2:
    pasta = 'enemy'
    lista = inimigo
if tipo == 3:
    pasta = 'bos'
    lista = Boss

Name = input('Nome do personagen: ')
Health	= eint('quantidade de Vida: ')
Speed = eint('Velocidade: ')
Mp = eint('Estamina: ')
offsetX = eint('Offset Padrão X: ')
offsetY = eint('Offset Padrão Y: ')
delay = eint('delay padrão das animações: ')
bbox = (f'    bbox{3*' '}{offsetX-10} {offsetY-70} {20} {70}')
idle = 0
Attack1 = 0
Attack2 = 0
Attack3 = 0
walk = 0
run = 0
runattack = 0
grabattack = 0
grabattack2 = 0
special = 0
special2 = 0
RAN = 0

for c in lista:
    J = eint(f'quantos frames tera a animação {c}: ')
    if c == 'idle':
        idle = J
    if c == 'Attack1':
        Attack1 = J
    if c == 'Attack2':
        Attack2 = J
    if c == 'Attack3':
        Attack3 = J
    if c == 'walk':
        walk = J
    if c == 'run':
        run = J
    if c == 'runattack':
        runattack = J
    if c == 'grabattack':
        grabattack = J
    if c == 'grabattack2':
        grabattack2 = J
    if c == 'special':
        special = J
    if c == 'special2':
        special2 = J

print(f'')
print(F'{10*'-'}Arquivo do personagen{10*'-'}')
print(f'')

print(f'Name{8*' '}{Name}')
print(f'Health{6*' '}{Health}')
print(f'Speed{7*' '}{Speed}')
print(f'Mp{10*' '}{Mp}')
if tipo == 1:
    print(f'Type{8*' '}Player')
else:
    print(f'Type{8*' '}Enemy')
print(f'''riseinv{5*' '}0.4 1
gfxshadow   1
antigrab    2
Jumpheight  3
falldie     2
atchain     1 1 2 3
running	    20	3	2	1	1''')

if tipo == 1:
    print(f'candamage{3*' '}enemy npc obstacle')
else:
    print(f'candamage{3*' '}Player npc obstacle')
print(f'weapons{5*' '}{Name}_Knife {Name}_Sword {Name}_pipe {Name}_Kunai')
print(f'icon{8*' '}data/chars/{pasta}s/{Name}/icon.gif 1')
print(f'diesound{3*' '} data/chars/{pasta}s/{Name}/death.wav')
print('animationscript	    data/scripts/drago.c')
print(' ')
print(' ')
for c in range(1,5):
    print(f'remap   data/chars/{pasta}s/{Name}/idle00.gif   data/chars/{pasta}s/{Name}/map{c:02}.gif')
print()
print()

for c in lista:
    arc = 'idle'
    loop = 0
    if c == 'idle':
        arq = 'idle'
        loop = 1
        RAN = idle
    if c == 'Attack1':
        arc = 'A1'
        RAN = Attack1
    if c == 'Attack2':
        arc = 'A2'
        RAN = Attack2
    if c == 'Attack3':
        arc = 'A3'
        RAN = Attack3
    if c == 'walk':
        arc = 'Walk'
        RAN = walk
        loop = 1
    if c == 'Run':
        arc = 'Run'
        RAN = run
        loop = 1
    if c == 'runattack':
        arc = 'Ra1'
        RAN = run
    if c == 'grabattack':
        arc = 'Ga1'
        RAN = grabattack
    if c == 'grabattack2':
        RAN = grabattack2
        arc = 'Ga2'
    if c == 'special':
        arc = 'SP1'
        RAN = special
    if c == 'special2':
        RAN = special2
        arc = 'SP2'
    print(f'Anim {c}')
    print(f'    Loop{4*' '}{loop}')
    print(f'    delay{3*' '}{delay}')
    print(f'    offset{2*' '}{offsetX}  {offsetY}')
    print(bbox)
    for p in range(0,RAN+1):
        print(f'    frame   data/chars/{pasta}s/{Name}/{arc}{p:02}.gif')
    print()
    print()

print(f'''anim get
	loop	0
	delay	10
	offset	23 84
	frame	data/chars/{pasta}s/{Name}/get00.gif


anim jump
	loop	0
	delay	20
	offset	26 90
	bbox	11 5 32 84
	frame	data/chars/{pasta}s/{Name}/jump00.gif
	frame	data/chars/{pasta}s/{Name}/jump01.gif
	frame	data/chars/{pasta}s/{Name}/jump00.gif


anim jumpattack
	loop	0
	delay	7
	offset	43 85
	bbox	26 8 37 69
    hitfx	data/sounds/golpes/medio.wav
    Sound	data/sounds/golpes/Chut.wav
	frame	data/chars/{pasta}s/{Name}/ja100.gif
	attack1  28  8  57  56  8  1  0  0  0  20
	delay  20
	frame	data/chars/{pasta}s/{Name}/ja101.gif



anim jumpattack2
	loop	0
	delay	7
	offset	45 89
	bbox	25 19 45 57
	attack1	44 29 37 37 7 0  0  0  0  15
    hitfx	data/sounds/golpes/Forte.wav
    Sound	data/sounds/golpes/Chut.wav
	frame	data/chars/{pasta}s/{Name}/ja200.gif

anim jumpforward
	loop	0
	delay	7
	offset	45 88
	bbox	29 10 33 50
    hitfx	data/sounds/golpes/Forte.wav
    Sound	data/sounds/golpes/soco.wav
	Attack1  0
	frame	data/chars/{pasta}s/{Name}/ja300.gif
	delay  25
	attack1  16  36  82  31  7  1  0  0  0  15
	frame	data/chars/{pasta}s/{Name}/ja301.gif


anim runjumpattack
	loop	0
	delay	3
	offset	51 68
	bbox	52 21 34 30
	attack	48 20 42 32 7 1  0  0  0  15
    hitfx	data/sounds/golpes/Forte.wav
    Sound	data/sounds/golpes/Chut.wav
	frame	data/chars/{pasta}s/{Name}/rja100.gif

anim grab
	loop	0
	delay	100
	offset	51 102
	bbox	36 24 29 77
    cancel	0 9 0 j freespecial
    cancel	0 9 0 b A freespecial4
	frame	data/chars/{pasta}s/{Name}/grab00.gif

anim rise
	loop	0
	offset	49 70
	delay	10
	frame	data/chars/{pasta}s/{Name}/Rise00.gif
        @cmd  depost  0
        @cmd  throw  0  5  2  2  0  -1
        @cmd  clearL
	frame	data/chars/{pasta}s/{Name}/Rise01.gif
	frame	data/chars/{pasta}s/{Name}/Rise02.gif

anim land
	loop	0
	delay	25
	offset	23 84
	frame	data/chars/{pasta}s/{Name}/land.gif

anim pain
	loop	0
	offset	22 88
	bbox	13 22 28 68
	delay	15
	frame	data/chars/{pasta}s/{Name}/pain1.gif
	frame	data/chars/{pasta}s/{Name}/pain2.gif


anim pain2
	loop	0
	offset	21 88
	bbox	7 16 26 72
	delay	15
	frame	data/chars/{pasta}s/{Name}/pain2.gif
	frame	data/chars/{pasta}s/{Name}/pain1.gif

anim pain3
	loop	0
	offset	21 88
	bbox	7 16 26 72
	jumpframe  0  2  0  0
	delay	10
	frame	data/chars/{pasta}s/{Name}/Pain2.gif
	offset  56  86
	bbox  30  18  40  67
	frame	data/chars/{pasta}s/{Name}/fall100.gif
	offset  21  88
	bbox  10  23  31  62
	frame	data/chars/{pasta}s/{Name}/Pain1.gif


anim fall
	loop	0
	offset	50 83
	delay	20
    hitfx	data/sounds/golpes/Forte.wav
	Attack1  0
	frame	data/chars/{pasta}s/{Name}/fall100.gif
	attack  101
	hitfx  data/sounds/golpes/Forte.wav
	frame  data/chars/{pasta}s/{Name}/fall101.gif
	Attack1  0
	offset  47  55
	frame	data/chars/{pasta}s/{Name}/fall102.gif

anim fall2
	loop	0
	offset	50 83
	delay	20
	jumpframe  0  2  -3.5  0
    hitfx	data/sounds/golpes/Forte.wav
	Attack1  0
	frame	data/chars/{pasta}s/{Name}/fall100.gif
	attack  101
	hitfx  data/sounds/golpes/Forte.wav
	frame  data/chars/{pasta}s/{Name}/fall101.gif
	Attack1  0
	offset  47  55
	frame	data/chars/{pasta}s/{Name}/fall102.gif
#Shock

anim fall4
	loop	0
	offset	50 77
	delay	10
	Attack1  0
	frame	data/chars/{pasta}s/{Name}/fall200.gif
	frame	data/chars/{pasta}s/{Name}/fall201.gif
	frame	data/chars/{pasta}s/{Name}/fall200.gif
	frame	data/chars/{pasta}s/{Name}/fall201.gif
	frame	data/chars/{pasta}s/{Name}/fall200.gif
	frame	data/chars/{pasta}s/{Name}/fall201.gif
	frame	data/chars/{pasta}s/{Name}/fall200.gif
	offset  50  55
	frame	data/chars/{pasta}s/{Name}/fall102.gif
#Burn

anim fall5
	loop	0
	offset	50 77
	delay	10
	Attack1  0
	frame	data/chars/{pasta}s/{Name}/fall300.gif
	frame	data/chars/{pasta}s/{Name}/fall301.gif
	frame	data/chars/{pasta}s/{Name}/fall302.gif
	frame	data/chars/{pasta}s/{Name}/fall300.gif
	frame	data/chars/{pasta}s/{Name}/fall301.gif
	frame	data/chars/{pasta}s/{Name}/fall302.gif
	frame	data/chars/{pasta}s/{Name}/fall300.gif
	frame	data/chars/{pasta}s/{Name}/fall301.gif
	frame	data/chars/{pasta}s/{Name}/fall302.gif
	offset  43  55
	frame	data/chars/{pasta}s/{Name}/fall102.gif

anim fall9
	loop	0
	offset	21 88
	delay	999
	Attack1  0
	frame	data/chars/{pasta}s/{Name}/pain1.gif
	frame	data/chars/{pasta}s/{Name}/pain2.gif
	offset  48  84
	frame	data/chars/{pasta}s/{Name}/fall400.gif
	frame	data/chars/{pasta}s/{Name}/fall401.gif
	offset  57  70
	frame	data/chars/{pasta}s/{Name}/fall402.gif
	offset  41  70
	frame	data/chars/{pasta}s/{Name}/fall403.gif
	frame	data/chars/{pasta}s/{Name}/fall404.gif
	offset  44  58
	frame	data/chars/{pasta}s/{Name}/fall405.gif
	delay	50
	offset  41  70
	frame	data/chars/{pasta}s/{Name}/fall403.gif
	delay	999
	offset  44  58
	frame	data/chars/{pasta}s/{Name}/fall405.gif''')

cont = 1

while True:
    print()
    print()
    fsn = 0
    fs= SouN('#Quer adicionar um Freespecial?[S/N]: ')
    if fs == 'S':
        qfs = eint('#quantos frames tera o freespecial: ')
        nfs = input('#qual o nome dos arquivos: ')
        print()
        print()
        if cont == 1:
            print(f'Anim Freespecial:')
        else:
            print(f'Anim Freespecial{cont}:')
        print(f'    Loop    0')
        print(f'    delay{3 * ' '}{delay}')
        print(f'    offset{2 * ' '}{offsetX}  {offsetY}')
        print(bbox)
        for c in range(0,qfs+1):
            print(f'    frame   data/chars/{pasta}s/{Name}/{nfs}{c:02}.gif')
        cont += 1







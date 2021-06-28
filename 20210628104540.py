Vqueue = []
Vhead = 0
Vtail = 0
Nqueue = []
Nhead = 0
Ntail = 0


def inque(name, type):
    global Vhead, Vtail, Nhead, Ntail,Vqueue ,Nqueue
    if (type == 'V'):
        Vqueue.append(name)
        Vtail += 1
    else:
        Nqueue.append(name)
        Ntail += 1
        # print(Vqueue)

def getHead(type):
    global Vhead, Vtail, Nhead, Ntail,Vqueue ,Nqueue

    if (type == 'V'):
        # print(Vhead)
        return Vqueue[Vhead]
    else:
        # print(Nhead)
        return Nqueue[Nhead]

def outque(type):
    global Vhead, Vtail, Nhead, Ntail,Vqueue ,Nqueue
    if (type == 'V'):

        if (Vhead == Vtail):
            return None
        else:

            s = getHead(type)
            Vhead += 1
            return s

    else:

        if (Nhead == Ntail):
            return None
        else:
            s= getHead(type)
            Nhead += 1
            return  s




if __name__ == '__main__':

    M = 0
    M = int(input())
    while M > 0:
        M -= 1
        op = input().split()

        # print(op[0])

        if op[0] == 'IN':


            inque(op[1], op[2])
            # print('in')
        else:

            outque(op[1])
            # print('out')
        # print("VVVVV",Vqueue)
        # print("NNNN",Nqueue)
        # print(M)

    s = outque('V')
    while s!=None:
        print(s)
        s = outque('V')

    s = outque('N')
    while s != None:
        print(s)
        s = outque('N')
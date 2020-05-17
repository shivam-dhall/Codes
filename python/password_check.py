l=0
u=0
sc=0
al=0
size=0

sp=['@','#','$','%']

a="HG@vvv23Hgf"

size=len(a)

for i in a:
    if(i.islower()):
        l=l+1
    if(i.isupper()):
        u=u+1
    if(i.isalpha()):
        al+=1

for j in sp:
    for k in a:
        if(k==j):
            sc+=1
            break

print(sp[0])
if(sc>0 and l>0 and u>0 and al>0 and size >8 and size<17):
    print("Password accepted")
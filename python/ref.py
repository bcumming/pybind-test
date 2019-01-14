import ref

ctx = ref.context()

print(ctx)
print('------------------------')

a = ctx.atom(0)

a.x = 42
a.y = 4

print(a)
print(ctx)

b = a

b.x = -42
b.y = 314

print('------------------------')
print(a)
print(b)
print(ctx)

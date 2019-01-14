import inheritance as I
import sys

class Impl(I.C):
    def generate(self):
        return 42

class Wimpl(I.C):
    def generate(self):
        x = I.wupple()
        x.widge = 'the answer is'
        x.wodge = 42
        return x

i = Wimpl()
a = I.make(i)

print('from python side\n  ', i.generate())
print('from C side\n  ',      I.generate(a))

x = 3
print(dir(x))
print(dir(i))
print(i.__class__)

b = I.bar()
print(b.__class__)

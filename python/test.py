import sequence as s
seq = s.make_regular_sequence(3, 1.5)
print('front: ', seq.front())
print('pop')
seq.pop()
print('front: ', seq.front())

s.print(seq, 20)

s.popper(seq, 10)

s.print(seq,50)

# make our own sequence type that extends the c++ type
class universal_seq(s.sequence):
    def pop(self):
        pass

    def front(self):
        return 42

# instantiate a copy of our custom type
seq = universal_seq()

# print using the interface we defined in Python
print('front: ', seq.front())
print('pop')
seq.pop()
print('front: ', seq.front())

# pass to a C++ function
s.print_first_n(seq, 10)


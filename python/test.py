import module
seq = module.make_regular_sequence(3, 1.5)
print('front: ', seq.front())
print('pop')
seq.pop()
print('front: ', seq.front())
module.print(seq, 20)

module.popper(seq, 10)

module.print(seq,50)

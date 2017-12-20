from group import group_description, cell_kind

g = group_description(cell_kind.cable, [2, 3, 5, 7, 11, 13, 17, 19])
print('printing gids for cell with kind: ', g.kind)
for gid in g.gids:
    print(gid)

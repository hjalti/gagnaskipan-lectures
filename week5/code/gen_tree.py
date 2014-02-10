import random

class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def gen_random_tree(p = 1):
    if random.random() > p:
        return None
    return TreeNode(random.randint(0,1000),
            gen_random_tree(p*0.9),
            gen_random_tree(p*0.9))


def print_tree(t, indent = 0, end = '\n'):
    if t is None:
        print('%s()'%(' '*indent), end = end)
        return
    print('%s(%d'%(' '*indent, t.data))
    print_tree(t.left,  indent + 4)
    print_tree(t.right, indent + 4, end = '')
    print(')', end = end)



print_tree(gen_random_tree())

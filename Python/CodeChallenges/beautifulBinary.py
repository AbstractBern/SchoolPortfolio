def beautifulBinaryString(b):
    # remove occurences of '010' and return # of occurences
    import re
    result = [_.start() for _ in re.finditer('010', b)]
    return len(result)

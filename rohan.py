import re

f = open("output.txt", "r")

file_string = f.read()

device = re.search("Size of Application Image: (nRF\d+)", file_string).group(1)

ram_limit = re.search(device+"_RAM_LIMIT = (\d+)", file_string).group(1)

dec = re.search("   tex    data    bss    dec    hex    filename\n   (.*)    (.*)    (.*)    (.*)    (.*)    \/", file_string).group(4)
tex = re.search("   tex    data    bss    dec    hex    filename\n   (.*)    (.*)    (.*)    (.*)    (.*)    \/", file_string).group(1)

diff = int(dec) - int(tex)

if diff > int(ram_limit): 
    print("error ram limit over")
    exit(1)
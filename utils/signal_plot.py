import numpy as np
import matplotlib.pyplot as plt
from struct import iter_unpack

data = []
with open("music.bin", "rb") as fil:
    raw = fil.read()
    mi_iter = iter_unpack("d", raw)
    data = [x[0] for x in mi_iter]

bitrate = 44100
end = len(data) / bitrate;
x = np.linspace(0,end,len(data))

plt.plot(x,data)
plt.show()
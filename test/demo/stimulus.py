import libpy as lb
import numpy as np
import sys, os
import MotionClouds as mc

h = 1024
w = 1024
f = 32


fx, fy, ft = mc.get_grids(h, w, f)
color = mc.envelope_color(fx, fy, ft)
stimulus = np.zeros([h, w, f, 3])

import time
t0 = time.time()

for i in range(3):
    V_X=0.5*np.cos(i*2.*np.pi/3.)
    V_Y=0.5*np.sin(i*2.*np.pi/3.)
    stimulus[:, :, :, i] = mc.rectif( mc.random_cloud(color * mc.envelope_gabor(fx, fy, ft, V_X=V_X, V_Y=V_Y, B_theta=10.), seed=123456+i), contrast=.8)
stimulus /= stimulus.sum(axis=-1)[..., np.newaxis]
stimulus = (stimulus * 255).astype(int)
print time.time() - t0

#lb.saveMovie(stimulus, 'stimulus', vext='.webm')
lb.saveMovie(stimulus, 'isoluminance', vext='.gif')
#lb.show_stimulus(stimulus, 'stimulus')

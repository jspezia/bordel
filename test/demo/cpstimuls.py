import libpy as lb
import numpy as np
import sys, os
import MotionClouds as mc

h = 512
w = 512
f = 32

fx, fy, ft = mc.get_grids(h, w, f)
color = mc.envelope_color(fx, fy, ft)
env = color * mc.envelope_speed(fx, fy, ft)
env = env * mc.envelope_gabor(fx, fy, ft)
env = mc.random_cloud(env, seed=123456)
env = mc.rectif(env, contrast=1.)
env = env * 255
stimulus = np.zeros([h, w, f, 3]).astype(int)

stimulus[:, :, :, 0] = env
stimulus[:, :, :, 1] = 255 - env
stimulus[:, :, :, 2] = 127

#lb.saveMovie(stimulus, 'movie', vext='.gif')
lb.show_stimulus(stimulus, 'stimulus')

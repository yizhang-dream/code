import torch
import numpy as np

shape = (2,3)
rand_tensor = torch.rand(shape) # 生成一个从[0,1]均匀抽样的tensor。
print(rand_tensor)
randn_tensor = torch.randn(shape) # 生成一个从标准正态分布抽样的tensor。
print(randn_tensor)
ones_tensor = torch.ones(shape) #生成一个值全为1的tensor。
print(ones_tensor)
zeros_tensor = torch.zeros(shape) # 生成一个值全为0的tensor。
print(zeros_tensor)
twos_tensor = torch.full(shape, 2) #  生成一个值全为2的tensor。
print(twos_tensor)

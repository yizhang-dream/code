# -*- coding: utf-8 -*-
"""
Created on Mon Sep 22 17:32:00 2025

@author: 86178
"""

# 父类：二维向量
# color_vec.py
from colorama import init, Fore, Style

# 让 Windows 终端也识别 ANSI 颜色码
init(autoreset=True)

class Vec2D:
    """二维向量"""
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y

    def __add__(self, other: "Vec2D") -> "Vec2D":
        return Vec2D(self.x + other.x, self.y + other.y)

    def __str__(self) -> str:
        return f"({self.x}, {self.y})"

class ColorVec(Vec2D):
    """带颜色的向量"""
    COLOR_MAP = {
        "red": Fore.RED,
        "blue": Fore.BLUE,
        "green": Fore.GREEN,
        "yellow": Fore.YELLOW,
        "black": Fore.BLACK,
    }

    def __init__(self, x: float, y: float, color: str = "black"):
        super().__init__(x, y)
        self.color = color

    def __str__(self) -> str:
        fore = self.COLOR_MAP.get(self.color.lower(), "")
        return f"{fore}{super().__str__()}{Style.RESET_ALL}"

# 演示
if __name__ == "__main__":
    a = ColorVec(1, 2, "red")
    b = ColorVec(3, 4, "blue")
    c = a + b  # 返回普通 Vec2D，无颜色
    print("a =", a)      # 红色
    print("b =", b)      # 蓝色
    print("a + b =", c)  # 默认终端色
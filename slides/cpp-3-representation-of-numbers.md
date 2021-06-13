## 1. Numeric Literals
```c++
int i = 10;		// dez
int i = 010;		// okt
int i = 0x10;		// hex
char c = ‘A’;		// char == 65

float f = 0.5f;	// float
float f = 0.5e10f;	// float

double d = 0.5;	// double
double d = 0.5e10;	// double
```

---

## 2. Binary System

- Also: **Dual System**
- Representation of numbers with only **two** digits  *(0 and 1)*
„base 2 system“ 

- e.g. `11001001` *(binary)* instead of `201` *(decimal)*
  - Notation (**mathematical**, not C++): 
**11001001b** or **11001001<sub>2</sub>**


---

## 3. Numeral Systems

- **Base 2:**		binary / dual
- **Base 8:** 	octal
- **Base 10:**	decimal
- **Base 16:**	hexadecimal


---

## 4. Binary Counting

- 0000	= 0
- 0001	= 1
- 0010	= 2
- 0011	= 3
- 0100	= 4
- 0101	= 5
- 0110	= 6
- 0111	= 7
- 1000	= 8
- 1001	= 9


---

## 5. Binary Operations - 1
**NOT** 
|  ~  |  0  |  1  |
|---|---|---|
|   |  1  |  0  |


- Complement 
- in C++: `~`

- `~ 11001 = 00110`


---

## 6. Binary Operations - 2
**AND**
|  &  |  0  |  1  |
|---|---|---|
|  0  |  0  |  0  |
|  1  |  0  |  1  |

- In C++: `&`

- 11010 & 01010 = 01010

- *Useful to unset bits (i.e. set bits to 0)*


---

## 7. Binary Operations - 3
**OR**
|  \|  |  0  |  1  |
|---|---|---|
| 0  |  0 |  1 |
| 1  |  1 | 1  |

- In C++: `|`

`11010` | `01011` = `11011`

- Useful to set bits (to 1)

---

## 8. Binary Operations - 4
**XOR**
| ^  | 0  | 1  |
|---|---|---|
| 0  | 0  |  1 |
|  1 |  1 |  0 |

- Exclusive **or**
- In C++:`^`

`11010` ^ `01011` = `10001`

---

## 9. Binary Operations - 5
**NOR**
| NOR  | 0  | 1  |
|---|---|---|
| 0  | 1  |  0 |
|  1 |  0 |  0 |

- Negated **or**
- Used manly in electrical engineering

---

## 10. Binary Operations - 6
**NAND**
| NAND  | 0  | 1  |
|---|---|---|
| 0  | 1  |  1 |
|  1 |  1 |  0 |

- Negated **and**
- Used manly in electrical engineering


---

## 11. Inspirational Quote

**10b | ~10b**
			<sub>*- William Shakespeare*</sub>


---

## 12. Hehe

**There are 10 kinds of people...**
       
			*those who know binary 
					and those who don‘t*


---

## 13. Facts

- All logical operations can be expressed using only the **complement** and one of the **two-valued operations** (i.e. `OR`, `AND` or `XOR`) 
- Respectively `NAND` or `NOR` alone are sufficient


---

## 14. In Practice: Setting Bits
```c++
#define ONE   1		// 0001
#define TWO   2		// 0010
#define FOUR  4		// 0100
#define EIGHT 8		// 1000

int i = 0;
i = i | ONE;			// i = 0001;
i = i | EIGHT | FOUR;	// i = 1101;
```
- Bits can be **“set”** using the OR-Operator `|`
- Combination of **#defines** and **bitwise** `OR` used by many APIs, e.g. DirectX


---

## 15. In Practice: Testing Bits
```c++
#define ONE   1		// 0001
#define TWO   2		// 0010
#define FOUR  4		// 0100
#define EIGHT 8		// 1000

int i = 15;			// 1111
if (i & EIGHT)
{
	cout << „EIGHT bit is set!“ << endl;
}
```
- Using the `AND` operator & bits can be tested (if they are set)

---

## 16. In Practice: Unsetting Bits
```c++
#define ONE   1		// 0001
#define TWO   2		// 0010
#define FOUR  4 		// 0100
#define EIGHT 8		// 1000

int i = 15;			// 1111
i = i & ~EIGHT;		// 0111
i = i & ~ONE; 		// 0110
```
- Bits can be **“unset”** using AND-Operator & and the Complement-Operator `~`

---

## 17. Shifting Operations

- Shift left `<<`
- Shift right `>>`

`00010 << 1 = 00100`  

`00010 << 2 = 01000`  

`00010 >> 1 = 00001`  

`00010 >> 2 = 00000`


---

## 18. Shifting Operations - Use
```c++
#define ONE   (1<<0)		// 0001
#define TWO   (1<<1)		// 0010
#define FOUR  (1<<2)		// 0100
#define EIGHT (1<<3)		// 1000
```

- „more beautiful“ definitions of bit patterns
- Fast multiplication with / division by powers of two

---

## 19. Byte Order – “Endianess”

- Different processors store individual bytes of number in different orders
- It is important to know this when moving data between different machines
  - <sub>Network code</sub>
  - <sub>File formats</sub>

- **Little Endian (e.g. Intel)**
  - **Ascending** order, starting with *least significant byte*
  
  **0x12345678 =**  
  
|  78 | 56  | 34  | 12  |
|---|---|---|---|

- **Big Endian (e.g. Motorola)**
- **Descending order**, starting with *most significant byte*

**0x12345678 =**  

|  12 | 34  | 56  | 78  |
|---|---|---|---|


---

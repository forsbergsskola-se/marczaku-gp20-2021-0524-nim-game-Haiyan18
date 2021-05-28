
## 1. Expressions
```
expression = 	identifier | 
		number |
		„(“ expression „)“  |
		expression „+“ expression |
		expression „-“ expression |
		...
		expression „=“ expression
```
- Every expression is valid c++ statement!
- Including the following:
```c++
i = 10 + 2;
10 + 2;
2;
```


---

## 2. Values of Expressions

- Every expression has a **value**
- Some expressions have to be evaluated before others (e.g. * and / before + and -)
- We say that some operators take precedence before others (see pdf table)

- The value of an assignment operation is **always** the value assigned
- Some operations have to be read from the left (`+`, `-`, `*`, `/`), others from the right (`=`, `+=`, `*=` etc.)

```c++
int i, j, k, l;

i = j = k = l = 5;
```


---

## 3. Preincrement and Postincrement

- Operators `++` and `–` increase / decrease a value by one
- They exist in two versions:
  - `i++` *(postincrement)*
  - `++i` *(preinkrement)*

- Their difference is value of expression
  - Value of `i++` is old i *(before the increment)*
  - Value of `++i` is new i *(after the increment)*


---

### 5. Expressions With Side Effects
```c++
int i = 0, j = 0;

if( ++i  ||  ++j )
{
	cout << „yes!“ << endl;
}

cout << i << „ “ << j << endl;
```
- Expressions that **calculate** a value and at the same time **change** another variable are said to have a side effect
  - `++` and `--` are a typical case
  - **Note!** *These can be very dangerous! (i.e. try to avoid them!)*

---

## 6. Expression Shortcutting
```c++
int i = 0, j = 0;

if( ++i  ||  ++j )
{
	cout << „yes!“ << endl;
}

cout << i << „ “ << j << endl;
```
- **Why does the example above not work?**
  - `++i` is already `„true“` and the second sub-expression of `||` is never evaluated!
- This is called **expression shortcutting**
- It can be very useful, but also be a dangerous trap if you use expression with side effects!

---

## 7. Type-Casts
*Explicit cast*
```c++
int i = 10; 
float f = (float) i;
```

*Implicit cast*
```c++
int i = 10; 
float f = i;
```
- Conversion of one data type into another
- **Attention: may have different range of values! May lose precision and or truncate data!**

- Casts can also happen **implicitly**
- Compiler warns in such a case


---


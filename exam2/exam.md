# Ambiguity
- Left Derivation
- Right Derivation

$$\epsilon + \epsilon + \epsilon$$

$$E \Rightarrow E + E | \epsilon$$

---

$$0111$$
$$E \Rightarrow 01E | 1E|\epsilon$$

```c

int count(ASTnode *p) 

{ 
  if (p==NULL) return 0; 

        
  if (p->name == "john"){
        return ( count(p->next)
                + count (p->S1) 
                + count (p->S2)  + 1); 
  } else {
        return ( count(p->next)
                + count (p->S1) 
                + count (p->S2));   
  }
 
 
}
```

---

$$ E \Rightarrow  E - E | id$$

$$ E \Rightarrow  id - E | id$$
int x, y, *p;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;



y = 0 → Inicializa y como 0.
p = &y → O ponteiro p aponta para y.
x = *p → x recebe o valor de y (0).
x = 4 → x é atribuído 4.
(*p)++ → Incrementa o valor de y via ponteiro p (agora y = 1).
--x → Decrementa x (agora x = 3).
(*p) += x → Soma o valor de x a y (agora y = 1 + 3 = 4).
Valores finais:

x = 3
y = 4
p = endereço de y
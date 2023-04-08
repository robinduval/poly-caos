# poly-caos

! (NOT logique) : C'est un opérateur unaire qui inverse la valeur logique de son opérande. 
Si l'opérande est vrai (non nul), il retourne 0 (faux). Sinon, il retourne 1 (vrai).
Exemple : !0 => 1, !5 => 0

~ (NOT bit à bit) : C'est un opérateur unaire qui inverse chaque bit de son opérande.
Exemple : ~5 (en binaire : ~0000 0101) => 1111 1010 (en décimal : -6)

& (ET bit à bit) : C'est un opérateur binaire qui effectue l'opération ET bit à bit sur ses opérandes.
Exemple : 5 & 3 (en binaire : 0101 & 0011) => 0001 (en décimal : 1)

^ (OU EXCLUSIF bit à bit) : C'est un opérateur binaire qui effectue l'opération OU EXCLUSIF bit à bit sur ses opérandes. 
Le bit résultant est 1 si les bits comparés sont différents, sinon il est 0.
Exemple : 5 ^ 3 (en binaire : 0101 ^ 0011) => 0110 (en décimal : 6)

| (OU bit à bit) : C'est un opérateur binaire qui effectue l'opération OU bit à bit sur ses opérandes. Le bit résultant est 1 si au moins un des bits comparés est 1, sinon il est 0.
Exemple : 5 | 3 (en binaire : 0101 | 0011) => 0111 (en décimal : 7)

(addition) + : C'est un opérateur binaire qui additionne ses deux opérandes.
Exemple : 5 + 3 => 8

(décalage à gauche) << : C'est un opérateur binaire qui décale les bits de l'opérande de gauche vers la gauche par un nombre de positions spécifié par l'opérande de droite. Des zéros sont insérés à droite.
Exemple : 5 << 2 (en binaire : 0101 << 2) => 10100 (en décimal : 20)

(décalage à droite) >> : C'est un opérateur binaire qui décale les bits de l'opérande de gauche vers la droite par un nombre de positions spécifié par l'opérande de droite. Pour les types non signés, des zéros sont insérés à gauche. Pour les types signés, le bit de signe est copié pour préserver le signe.
Exemple (non signé) : 20 >> 2 (en binaire : 10100 >> 2) => 0101 (en décimal : 5)
Exemple (signé) : -6 >> 2 (en binaire : 1111 1010 >> 2) => 1111 1110 (en décimal : -2)

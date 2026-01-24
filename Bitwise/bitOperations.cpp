#include<iostream>
using namespace std;

// ╔══════════════════════════════════════════════════════════════════╗
// ║                    OPERAÇÕES BÁSICAS COM BITS                    ║
// ╚══════════════════════════════════════════════════════════════════╝

// ┌─────────────────────────────────────────────────────────────────┐
// │ 1. GET - Obter o valor do bit na posição i                      │
// └─────────────────────────────────────────────────────────────────┘
int getIthBit(int n, int i){
    int mask = (1 << i);        // Cria máscara: 00001000 (1 na posição i)
    return (n & mask) > 0 ? 1 : 0;
}
/*
    Exemplo: n = 5 (0101), i = 2
    
    mask = 1 << 2 = 0100
    
        0101  (n = 5)
      & 0100  (mask)
      ──────
        0100  → > 0 → retorna 1
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 2. SET - Define o bit i como 1                                  │
// └─────────────────────────────────────────────────────────────────┘
void setIthBit(int &n, int i){
    int mask = (1 << i);
    n = (n | mask);             // OR: qualquer bit | 1 = 1
}
/*
    Exemplo: n = 5 (0101), i = 1
    
    mask = 1 << 1 = 0010
    
        0101  (n = 5)
      | 0010  (mask)
      ──────
        0111  → n = 7
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 3. CLEAR - Define o bit i como 0                                │
// └─────────────────────────────────────────────────────────────────┘
void clearIthBit(int &n, int i){
    int mask = ~(1 << i);       // Inverte: 11110111 (0 na posição i)
    n = (n & mask);             // AND: qualquer bit & 0 = 0
}
/*
    Exemplo: n = 7 (0111), i = 1
    
    1 << 1    = 0010
    ~(1 << 1) = 1101  (mask)
    
        0111  (n = 7)
      & 1101  (mask)
      ──────
        0101  → n = 5
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 4. UPDATE - Atualiza o bit i para o valor v (0 ou 1)            │
// └─────────────────────────────────────────────────────────────────┘
void updateIthBit(int &n, int i, int v){
    clearIthBit(n, i);          // Primeiro limpa o bit (coloca 0)
    int mask = (v << i);        // Move o valor v para a posição i
    n = n | mask;               // Aplica o novo valor
}
/*
    Exemplo: n = 5 (0101), i = 0, v = 0
    
    Após clearIthBit: n = 4 (0100)
    mask = 0 << 0 = 0000
    
        0100
      | 0000
      ──────
        0100  → n = 4
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 5. TOGGLE - Inverte o bit i (0→1 ou 1→0)                        │
// └─────────────────────────────────────────────────────────────────┘
void toggleIthBit(int &n, int i){
    int mask = (1 << i);
    n = (n ^ mask);             // XOR: 0^1=1, 1^1=0 (inverte)
}
/*
    Exemplo: n = 5 (0101), i = 2
    
    mask = 1 << 2 = 0100
    
        0101  (n = 5)
      ^ 0100  (mask)
      ──────
        0001  → n = 1
*/

// ╔══════════════════════════════════════════════════════════════════╗
// ║                     OPERAÇÕES AVANÇADAS                          ║
// ╚══════════════════════════════════════════════════════════════════╝

// ┌─────────────────────────────────────────────────────────────────┐
// │ 6. CLEAR LAST I BITS - Limpa os últimos i bits                  │
// └─────────────────────────────────────────────────────────────────┘
void clearLastIBits(int &n, int i){
    int mask = (-1 << i);       // -1 = todos 1s, desloca i posições
    n = (n & mask);
}
/*
    Exemplo: n = 15 (1111), i = 2
    
    -1        = 11111111...
    -1 << 2   = 11111100 (mask)
    
        1111
      & 1100
      ──────
        1100  → n = 12
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 7. CLEAR BITS IN RANGE - Limpa bits de j até i                  │
// └─────────────────────────────────────────────────────────────────┘
void clearBitsInRange(int &n, int i, int j){
    int a = (~0 << (j + 1));    // 1s acima de j:    11110000
    int b = (1 << i) - 1;       // 1s abaixo de i:   00000011
    int mask = a | b;           // Combina:          11110011
    n = n & mask;
}
/*
    Exemplo: n = 31 (11111), i = 1, j = 3
    
    a = ~0 << 4 = 11110000
    b = (1 << 1) - 1 = 0001
    mask = 11110001
    
        11111
      & 10001
      ──────
        10001  → n = 17
*/

// ╔══════════════════════════════════════════════════════════════════╗
// ║                    FUNÇÕES UTILITÁRIAS                           ║
// ╚══════════════════════════════════════════════════════════════════╝

// ┌─────────────────────────────────────────────────────────────────┐
// │ 8. COUNT SET BITS - Conta quantos bits são 1                    │
// └─────────────────────────────────────────────────────────────────┘
int countSetBits(int n){
    int count = 0;
    while(n > 0){
        count += (n & 1);       // Verifica bit menos significativo
        n = n >> 1;             // Desloca para direita
    }
    return count;
}
/*
    Exemplo: n = 13 (1101)
    
    Iteração 1: 1101 & 1 = 1, count = 1, n = 0110
    Iteração 2: 0110 & 1 = 0, count = 1, n = 0011
    Iteração 3: 0011 & 1 = 1, count = 2, n = 0001
    Iteração 4: 0001 & 1 = 1, count = 3, n = 0000
    
    Retorna 3
*/

// Método mais eficiente (Brian Kernighan)
int countSetBitsFast(int n){
    int count = 0;
    while(n){
        n = n & (n - 1);        // Remove o bit 1 mais à direita
        count++;
    }
    return count;
}
/*
    Exemplo: n = 13 (1101)
    
    n = 1101, n-1 = 1100, n & (n-1) = 1100, count = 1
    n = 1100, n-1 = 1011, n & (n-1) = 1000, count = 2
    n = 1000, n-1 = 0111, n & (n-1) = 0000, count = 3
    
    Retorna 3 (apenas 3 iterações!)
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 9. IS POWER OF TWO - Verifica se é potência de 2                │
// └─────────────────────────────────────────────────────────────────┘
bool isPowerOfTwo(int n){
    return (n > 0) && ((n & (n - 1)) == 0);
}
/*
    Potências de 2 têm apenas UM bit 1:
    
    1  = 0001     8  = 1000
    2  = 0010     16 = 10000
    4  = 0100
    
    n = 8 (1000), n-1 = 7 (0111)
    1000 & 0111 = 0000 → É potência de 2!
    
    n = 6 (0110), n-1 = 5 (0101)
    0110 & 0101 = 0100 ≠ 0 → NÃO é potência de 2
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 10. IS ODD/EVEN - Verifica paridade                             │
// └─────────────────────────────────────────────────────────────────┘
bool isOdd(int n){
    return (n & 1) == 1;        // Bit menos significativo = 1 → ímpar
}

bool isEven(int n){
    return (n & 1) == 0;        // Bit menos significativo = 0 → par
}
/*
    Números pares terminam em 0:  2=10, 4=100, 6=110
    Números ímpares terminam em 1: 1=01, 3=11, 5=101
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 11. SWAP - Troca dois números sem variável auxiliar             │
// └─────────────────────────────────────────────────────────────────┘
void swapNumbers(int &a, int &b){
    a = a ^ b;
    b = a ^ b;                  // b = (a^b)^b = a
    a = a ^ b;                  // a = (a^b)^a = b
}
/*
    Propriedades do XOR:
    - a ^ a = 0
    - a ^ 0 = a
    - a ^ b ^ b = a
    
    Exemplo: a = 5, b = 3
    a = 5 ^ 3 = 6
    b = 6 ^ 3 = 5  (agora b = valor original de a)
    a = 6 ^ 5 = 3  (agora a = valor original de b)
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 12. MULTIPLY/DIVIDE BY 2^k - Multiplicar/Dividir por potência   │
// └─────────────────────────────────────────────────────────────────┘
int multiplyByPowerOf2(int n, int k){
    return n << k;              // n * 2^k
}

int divideByPowerOf2(int n, int k){
    return n >> k;              // n / 2^k
}
/*
    Exemplo: n = 5 (0101)
    
    5 << 1 = 1010 = 10  (5 * 2)
    5 << 2 = 10100 = 20 (5 * 4)
    
    20 >> 2 = 0101 = 5  (20 / 4)
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 13. GET LOWEST SET BIT - Pega bit 1 mais à direita              │
// └─────────────────────────────────────────────────────────────────┘
int getLowestSetBit(int n){
    return n & (-n);            // -n é o complemento de 2
}
/*
    Exemplo: n = 12 (1100)
    
    n  = 01100
    -n = 10100 (complemento de 2)
    
    01100 & 10100 = 00100 = 4
    
    O bit 1 mais baixo está na posição 2 (valor 4)
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 14. TURN OFF RIGHTMOST BIT - Desliga bit 1 mais à direita       │
// └─────────────────────────────────────────────────────────────────┘
int turnOffRightmostBit(int n){
    return n & (n - 1);
}
/*
    Exemplo: n = 12 (1100)
    
    n   = 1100
    n-1 = 1011
    
    1100 & 1011 = 1000 = 8
*/

// ┌─────────────────────────────────────────────────────────────────┐
// │ 15. EXTRACT BITS - Extrai k bits a partir da posição p          │
// └─────────────────────────────────────────────────────────────────┘
int extractBits(int n, int p, int k){
    return (n >> p) & ((1 << k) - 1);
}
/*
    Exemplo: n = 171 (10101011), p = 2, k = 4
    
    n >> 2 = 00101010
    (1 << 4) - 1 = 10000 - 1 = 01111
    
    00101010 & 00001111 = 00001010 = 10
*/
int convertToBinaty(int n){
    int ans = 0;
    int p = 1;
    while( n > 0){
        int last_bit = (n & 1);
        ans += p*last_bit;
        p *= 10;
        ans = n>>1;
    }
    return ans;
}

// ╔══════════════════════════════════════════════════════════════════╗
// ║                         MAIN DE TESTE                            ║
// ╚══════════════════════════════════════════════════════════════════╝

int main(){
    cout << "═══════════════════════════════════════════" << endl;
    cout << "      DEMONSTRAÇÃO DE OPERAÇÕES BITWISE    " << endl;
    cout << "═══════════════════════════════════════════" << endl;
    
    int n = 13;  // 1101 em binário
    cout << "\nNúmero inicial: " << n << " (1101 em binário)\n" << endl;
    
    // GET
    cout << "1. getIthBit(" << n << ", 2) = " << getIthBit(n, 2) << endl;
    
    // SET
    int temp = n;
    setIthBit(temp, 1);
    cout << "2. setIthBit(" << n << ", 1) = " << temp << endl;
    
    // CLEAR
    temp = n;
    clearIthBit(temp, 2);
    cout << "3. clearIthBit(" << n << ", 2) = " << temp << endl;
    
    // TOGGLE
    temp = n;
    toggleIthBit(temp, 0);
    cout << "4. toggleIthBit(" << n << ", 0) = " << temp << endl;
    
    // COUNT BITS
    cout << "5. countSetBits(" << n << ") = " << countSetBits(n) << endl;
    
    // POWER OF TWO
    cout << "6. isPowerOfTwo(8) = " << (isPowerOfTwo(8) ? "true" : "false") << endl;
    cout << "   isPowerOfTwo(13) = " << (isPowerOfTwo(13) ? "true" : "false") << endl;
    
    // ODD/EVEN
    cout << "7. isOdd(" << n << ") = " << (isOdd(n) ? "true" : "false") << endl;
    
    // MULTIPLY/DIVIDE
    cout << "8. " << n << " * 4 (<<2) = " << multiplyByPowerOf2(n, 2) << endl;
    cout << "   " << n << " / 2 (>>1) = " << divideByPowerOf2(n, 1) << endl;
    
    // SWAP
    int a = 5, b = 10;
    cout << "9. Antes do swap: a=" << a << ", b=" << b << endl;
    swapNumbers(a, b);
    cout << "   Depois do swap: a=" << a << ", b=" << b << endl;
    
    cout << "\n═══════════════════════════════════════════" << endl;
    
    return 0;
}
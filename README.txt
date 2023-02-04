Tema 1 : MINIPROCESOR

Task 1 :
In taskul 1 eu am creat un mic proces in urma caruia, in priul pas, 
am citit un numar pe 32 de biti.

Primii cei mai semnificativi 3 biti ai acestui numar i-am transformat din binar 
in decimal. Numarul citit initial l-am siftat la stanga cu 3 pozitii pentru a 
elimina bitii deja folositi.

Rezultatul obtinut l-am adunat cu 1 si am primit astfel numarul de operatii 
ce vor aparea pe ecran (+ || - || * || /).
Aceste operatii reprezinta gruparea a cate 2 biti din numar dupa siftare.
Bitii se grupeaza in modul urmator : 00 - "+", 01 - "-", 10 - "*", 11 - "/".
Prin intermediulu unei masti cu 1 pe pozitia cea mai semnificativa si 
restul de 31 zerouri, eu am determinat care este bitul cel mai semnificativ 
al numarului.

In cazul meu, numarul se sifteaza la stanga cu cate o pozitie dupa determinarea 
primului bit semnificativ din numar. Inainte de a doua siftare, rezulta ca deja 
am citi cei 2 biti necesari, din care am si creat operatiunea ce se va afisa
pe ecran.

Dupa citirea de N ori a grupurilor de cate 2 biti, am mai citit inca 4 biti prin 
intermediul unei masti care are valoarea 7 si sa siftat la stanga 
cu 28 de poziti. Acesti 4 biti vor reprezenta valoarea unei dimensiuni 
care va fi adunata cu 1 si apoi afisata pe ecran. Aceasta dimensiune se va utiliza 
in taskul 2.


Task 2 :
In taskul dat am copiat procesul din taskul 1 cu ceva modificari. In locul 
afisarii operatiilor pe ecran eu le-am pus intr-un vector, pentru a le 
folosi la final. In cadrul acestui task am folosit o formula speciala : 
((N + 1) * Dim) / 16. 
Daca rezultatul acestor calcule are restul 0, acest lucru va insemna ca 
voi citi de la tastatura atatea numere cat a dat si raspunsul. 
Dar daca restul nu e 0 raspunsul l-am adunat cu 1.

In acest task voi utiliza si dimensiunea. Conform cerintelor, dimensiunea 
in acest task este egala cu puterile lui 2 : 1, 2, 4, 8, 16.
Conform dimensiunii, numarul citit de tip unsigned short int a fost impartit 
in biti la numar egal cu dimensiunea. Acesti biti au fost transforati in decimal 
si au reprezentat operantii cu care voi lucra spre final.
Fiecare operand transformat in decimal l-am pus intr-un vector pe pozitii 
consecutive.

Dupa ce am citit toate numerele am lucrat pe vectorul de operatii automat
realizand calculele pe vectorul de operanzi. Pe vectorul de operatii am 
lucrat in ordinea aparitiilor operatiilor, fara a lua in calcul faptul 
ca impartirea si inmultirea se fac inaintea adunarii si scaderii.


Task 3 :
In cadrul acestui task iarasi am copiat procesul din taskul 2, 
cu modificari minore. In acest task nu mai este data dimensiunea ca fiind 
numere putere a lui 2, din acest motiv dimensiunea poate avea orice valoare.
In acest caz eu am folosit un vector special pe care voi lucra.

Citind numarul de tipul unsigned int short, si stiind dimensiunea cu care 
voi lucra, eu am aflat prin impartirea lui 16 la Dim cati operanzi maxim voi 
putea afla din fiecare numar citit. Bitii ramasi nefolositi. Daca foloseam
intraga dimensiune, atunci calculam operandul si il puneam in vectoriul pentru 
operanzi, in caz contrar bitii ramasi nefolositi i-am pus intr-un vector pe 
numarul de pozitii cati biti au ramas nefolositi. 

Punand fiecare bit pe o pozitie din vector, am folosit un contor care 
il foloseam la citirea numarului urmator. Daca am avut biti ramasi, 
atunci la citirea urmatorului numar am pus de pe pozitia contorului 
"diferenta dintre dimensiune si contor" biti.

Dupa aceasta faceam urmatorul operand pe care il puneam in vectorul operanzilor.
In acest task am facut calculele la fel ca si in taskul 2.


Task 4 :
In taskul 4 am copiat tot procesul din taskul 3 si am modificat doar finalul.
Finanul a fost modificat dor prin faptul ca am pus in prioritate 
adunarea si scaderea cu inmultirea si impartirea. Adica in primul rand am 
efectut inmultirea sau impartirea, dupa care adunarea sau scaderea.


Contacte : 

Butcan Vlad 

Nr. telefon : 0763834822

Email: butcanvlad10@gmail.com

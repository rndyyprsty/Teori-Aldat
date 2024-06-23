# <h1 align="center">Tugas 3 Algoritma Struktur Data</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## 1.	Berikan penjelasan dan contoh program(beserta penjelasan alur program) dari masing-masing materi struktur data berikut:
a.	Priority Queue 
b.	Hash Table 
c.	Rekursif 
d.	Graph & Tree

### A. Priority Queue

Priority Queue adalah jenis Queue yang berbasis pada prinsip HPIFO (Highest Priority In First Out). Ini berbeda dengan Queue biasa yang sangat bergantung pada urutan kedatangan elemen, di mana elemen yang datang pertama akan diambil atau dihapus terlebih dahulu. Sebaliknya, dalam Priority Queue, elemen yang diambil atau dihapus adalah elemen yang memiliki prioritas tertinggi. Jika prioritas ditentukan oleh waktu kedatangan, maka Priority Queue akan berfungsi seperti Queue biasa[1].

Priority Queue dibagi menjadi dua jenis:
1. Ascending Priority Queue: Queue di mana elemen diurutkan berdasarkan prioritas yang meningkat, dari prioritas terendah ke tertinggi.
2. Descending Priority Queue: Queue di mana elemen diurutkan berdasarkan prioritas yang menurun, dari prioritas tertinggi ke terendah.

Ada dua cara untuk merepresentasikan Priority Queue, yaitu menggunakan Set dan List. Dengan Set, data dimasukkan ke dalam Queue berdasarkan waktu kedatangan, tetapi pengambilannya tetap berdasarkan prioritas. Keuntungan menggunakan Set adalah operasi enQueue (menambah elemen) sangat cepat dan sederhana, namun operasi deQueue (menghapus elemen) menjadi sangat kompleks karena memerlukan pencarian elemen dengan prioritas tertinggi. Sebaliknya, dengan List, data di enQueue dan di deQueue berdasarkan prioritas secara langsung[2].

#### Contoh Program

```
#include <iostream>
#include <queue>
#include <vector>

struct Elemen {
    int value;
    int priority;

    bool operator<(const Elemen& other) const {
        return priority < other.priority;
    }
};

int main() {
    std::priority_queue<Elemen> pq;

    pq.push(Elemen{1, 2});
    pq.push(Elemen{2, 1});
    pq.push(Elemen{3, 5});
    pq.push(Elemen{4, 3});

    while (!pq.empty()) {
        Elemen top = pq.top();
        pq.pop();
        std::cout << "Value: " << top.value << ", Priority: " << top.priority << std::endl;
    }

    return 0;
}
```

#### Penjelasan Program

Program ini membuat struct Element yang memiliki dua atribut: value dan priority. Operator < di-overload untuk menentukan bahwa elemen dengan prioritas lebih tinggi memiliki prioritas lebih besar dalam queue. std::priority_queue<Element> digunakan untuk mendeklarasikan priority queue yang akan menyimpan elemen-elemen bertipe Element. Elemen-elemen ditambah ke dalam priority queue dengan metode push yang memakai nilai dan prioritas tertentu, seperti pq.push(Element{1, 2}) yang menambahkan elemen dengan nilai 1 dan prioritas 2. Selama queue tidak kosong, elemen dengan prioritas tertinggi diambil menggunakan metode top dan dihapus dari queue menggunakan metode pop. Elemen-elemen ini kemudian dicetak menggunakan std::cout.

### B. Hash Table

Tabel hash adalah metode untuk menyimpan data dalam memori dalam bentuk baris dan kolom sehingga dapat diakses dengan cepat. Setiap pertemuan antara baris dan kolom dalam tabel hash, tempat data disimpan, disebut slot. Tabel hash terdiri dari dua bagian utama: sebuah larik (array) dan fungsi pemetaan yang disebut fungsi hash. Fungsi hash adalah alat yang memetakan kunci yang diberikan ke dalam larik, yang berarti fungsi ini mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel atau larik yang telah disediakan[3].

Fungsi hash digunakan untuk memetakan nilai tertentu ke indeks dalam array berdasarkan kunci yang diberikan. Fungsi hash harus mudah dihitung, memastikan bahwa dua kunci berbeda dipetakan ke dua sel berbeda dalam array, dan mendistribusikan kunci secara merata ke seluruh sel.

Operasi yang dapat dilakukan pada Tabel Hash meliputi:
- Insert: Menambahkan sebuah kunci dan nilai, serta memasukkan nilai tersebut ke dalam tabel.
- Find: Mencari nilai yang terkait dengan kunci yang diberikan.
- Remove: Menghapus nilai yang terkait dengan kunci yang diberikan.
- GetIterator: Mengembalikan iterator yang memeriksa nilai satu per satu[4].

#### Contoh Program

```
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

class HashTable {
    int capacity;
    vector<list<int>> table;

public:
    HashTable(int size) {
        capacity = size;
        table.resize(capacity);
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void displayHashTable() {
        for (int i = 0; i < capacity; i++) {
            cout << i;
            for (auto x : table[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    int keys[] = {15, 11, 27, 8, 12};
    int size = sizeof(keys) / sizeof(keys[0]);

    HashTable ht(7);

    for (int i = 0; i < size; i++) {
        ht.insertItem(keys[i]);
    }

    ht.displayHashTable();

    ht.deleteItem(12);
    cout << "setelah menghapus 12:\n";
    ht.displayHashTable();

    return 0;
}
```

#### Penjelasan Program

Program ini mendefinisikan sebuah hash table sederhana menggunakan kelas `HashTable`. Kelas ini menyimpan elemen dalam bentuk vektor dari daftar (list). Konstruktur `HashTable` menginisialisasi ukuran tabel dan menentukan kapasitasnya. Fungsi `hashFunction` digunakan untuk menentukan indeks penyimpanan elemen berdasarkan kunci yang diberikan dengan operasi modulus. Elemen-elemen dimasukkan ke dalam hash table menggunakan fungsi `insertItem`, yang menambahkan elemen ke daftar pada indeks yang sesuai. Untuk menghapus elemen, fungsi `deleteItem` digunakan, yang menghapus elemen dari daftar pada indeks yang ditentukan oleh fungsi hash. Program utama (`main`) mendemonstrasikan penggunaan kelas `HashTable` dengan memasukkan beberapa elemen ke dalam hash table dan menampilkannya. Setelah itu, satu elemen dihapus dari hash table dan tabel hash ditampilkan kembali untuk menunjukkan hasil penghapusannya. Program ini mengilustrasikan konsep dasar hash table seperti hashing, penanganan tabrakan dengan chaining (daftar berantai), serta operasi dasar seperti penyisipan dan penghapusan elemen.


### C. Rekursif

Rekursi adalah metode pengulangan yang melibatkan penggunaan dirinya sendiri. Dalam pemrograman, fungsi rekursif merupakan bentuk perulangan tanpa menggunakan iterasi. Secara umum, fungsi rekursif sama seperti fungsi lainnya; dapat dipanggil, menerima parameter, mengembalikan nilai, dan memiliki sifat serupa. Perbedaannya terletak pada kemampuannya untuk memanggil dirinya sendiri, menciptakan efek pengulangan. Ini terjadi karena fungsi tersebut memanggil dirinya sendiri, menghasilkan pengulangan. Proses ini berhenti saat kondisi tertentu terpenuhi, atau bisa berlanjut tanpa batas, bahkan menyebabkan kesalahan karena pemanggilan tak berujung. Konsep ini mirip dengan dua cermin yang saling memantulkan, menciptakan pantulan tanpa henti. Akhirnya, fenomena ini menghasilkan efek cermin dalam cermin, membentuk rangkaian yang terus berlanjut[5].

Jenis Rekursif
Ada beberapa jenis rekursif yaitu:
1. Rekursi Langsung (Direct Recursion)
Rekursi langsung adalah jenis rekursif di mana fungsi memanggil dirinya sendiri secara langsung. Contoh: fungsi fun(n) memanggil dirinya sendiri dengan parameter n-1.
2. Rekursi Tidak Langsung (Indirect Recursion)
Rekursi tidak langsung adalah jenis rekursif di mana fungsi memanggil fungsi lain yang kemudian memanggil fungsi asli. Contoh: fungsi fun1() memanggil fungsi fun2() yang kemudian memanggil fungsi fun1().
3. Rekursi Akhir (Tail Recursion)
Rekursi akhir adalah jenis rekursif di mana fungsi memanggil dirinya sendiri dan recursive call adalah statement terakhir dalam fungsi. Contoh: fungsi fun(n) memanggil dirinya sendiri dengan parameter n-1 dan tidak melakukan operasi lain.
4. Rekursi Pohon (Tree Recursion)
Rekursi pohon adalah jenis rekursif di mana fungsi memanggil dirinya sendiri lebih dari satu kali. Contoh: fungsi fun(n) memanggil dirinya sendiri dengan parameter n-1 dan n-2[6].

#### Contoh Program

```
#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "masukkan integer positif: ";
    cin >> number;

    if (number < 0)
        cout << "Factorial tidak ada." << endl;
    else
        cout << "Faktorial dari " << number << " adalah " << factorial(number) << endl;

    return 0;
}
```

#### Penjelasan Program

Program ini mendefinisikan fungsi rekursif bernama `factorial` untuk menghitung faktorial dari sebuah angka positif. Fungsi ini memiliki kondisi dasar di mana jika `n` kurang dari atau sama dengan 1, ia akan mengembalikan nilai 1. Untuk nilai `n` yang lebih besar dari 1, fungsi akan memanggil dirinya sendiri dengan nilai `n - 1` dan mengalikan hasilnya dengan `n`. Dengan demikian, faktorial dihitung secara bertahap dengan mengurangi nilai `n` sampai mencapai kondisi dasar. Di bagian `main`, program meminta pengguna untuk memasukkan sebuah angka bulat positif. Jika pengguna memasukkan angka negatif, program akan menampilkan pesan bahwa faktorial dari angka negatif tidak ada. Jika angka yang dimasukkan positif, program akan memanggil fungsi `factorial` dan menampilkan hasilnya. Program ini mengilustrasikan cara kerja rekursi dalam menghitung faktorial, dengan memecah masalah besar menjadi masalah yang lebih kecil hingga mencapai kondisi dasar.

### D. Graph & Tree

#### Graf
Graf adalah sekumpulan titik (simpul) dalam bidang dua dimensi yang dihubungkan oleh garis-garis (sisi). Graf digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara mereka. Visualisasi graf dilakukan dengan menggambarkan objek sebagai titik (vertex) dan hubungan antara objek tersebut sebagai garis (edge). Graf merupakan cabang ilmu yang luas dengan berbagai aplikasi. Banyak struktur dapat diwakili oleh graf, dan banyak masalah dapat diselesaikan menggunakan graf. Graf sering digunakan untuk merepresentasikan jaringan, seperti jaringan jalan dengan kota sebagai simpul (vertex) dan jalan sebagai sisi (edge) yang bobotnya (weight) adalah panjang jalan tersebut[7].

Jenis-Jenis Graph
- Undirected Graph:
Urutan simpul dalam sebuah sisi tidak penting, misalnya sisi e1 bisa disebut AB atau BA.
- Directed Graph:
Urutan simpul berpengaruh, misalnya sisi AB adalah e1, sedangkan sisi BA adalah e8.
- Weighted Graph:
Setiap sisi memiliki nilai yang menunjukkan hubungan antara dua simpul, seperti panjang jalan antara dua titik atau jumlah kendaraan per hari yang melewati jalan tersebut.

#### Tree

Tree adalah kumpulan node yang terhubung satu sama lain membentuk struktur seperti pohon. Tree digunakan untuk merepresentasikan struktur hierarkis (one-to-many) secara grafis. Tree tidak mengandung sirkuit dan merupakan struktur data non-linear dengan hubungan hierarkis antar elemen[8].

Operasi-Operasi Pada Tree
- Create: Membentuk binary tree baru yang kosong.
- Clear: Mengosongkan binary tree yang ada.
- Empty Function: Memeriksa apakah binary tree kosong.
- Insert: Menambahkan node ke dalam tree sebagai root, left child, atau right child. Root hanya bisa ditambahkan jika tree kosong.
- Find: Mencari root, parent, left child, atau right child dari suatu node (tree tidak boleh kosong).
- Update: Mengubah isi node yang ditunjuk oleh pointer current (tree tidak boleh kosong).
- Retrieve: Mengetahui isi node yang ditunjuk oleh pointer current (tree tidak boleh kosong).
- DeleteSub: Menghapus subtree (node beserta seluruh turunannya) yang ditunjuk current. Setelah itu, pointer current berpindah ke parent dari node yang dihapus.
- Characteristic: Mengetahui karakteristik tree, seperti size, height, dan average length (tree tidak boleh kosong).
- Traverse: Mengunjungi seluruh node dalam tree satu per satu. Terdapat tiga cara traverse: PreOrder, InOrder, dan PostOrder .
- Preorder: Cetak isi node, kunjungi left child, kunjungi right child.
- Inorder: Kunjungi left child, cetak isi node, kunjungi right child.
- Postorder: Kunjungi left child, kunjungi right child, cetak isi node.

##### Contoh Program Graph

```
#include <iostream>
#include <list>
using namespace std;

class Graf {
    int V;
    list<int> *adj;

public:
    Graf(int V);
    void tambahEdge(int v, int w);
    void BFS(int s);
};

Graf::Graf(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graf::tambahEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graf::BFS(int s) {
    bool *dikunjungi = new bool[V];
    for(int i = 0; i < V; i++)
        dikunjungi[i] = false;

    list<int> antrian;
    dikunjungi[s] = true;
    antrian.push_back(s);

    list<int>::iterator i;

    while(!antrian.empty()) {
        s = antrian.front();
        cout << s << " ";
        antrian.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!dikunjungi[*i]) {
                dikunjungi[*i] = true;
                antrian.push_back(*i);
            }
        }
    }
}

int main() {
    Graf g(4);
    g.tambahEdge(0, 1);
    g.tambahEdge(0, 2);
    g.tambahEdge(1, 2);
    g.tambahEdge(2, 0);
    g.tambahEdge(2, 3);
    g.tambahEdge(3, 3);

    cout << "Breadth first traversal dimulai dari simpul 2:\n";
    g.BFS(2);

    return 0;
}
```
##### Penjelasan Program

Program ini membuat kelas Graf yang merepresentasikan sebuah graf berarah menggunakan daftar adjacency. Konstruktornya mengatur jumlah simpul (V) dan membuat array daftar untuk menyimpan tetangga dari setiap simpul. Fungsi tambahEdge menambahkan sebuah edge dari simpul v ke simpul w. Fungsi BFS (Breadth-First Search) memulai penjelajahan dari simpul tertentu dan mengeksplorasi semua simpul yang terhubung menggunakan antrian untuk melacak simpul-simpul yang akan dijelajahi berikutnya. Dalam program utama, kita membuat graf dengan 4 simpul, menambahkan beberapa edge, lalu menjalankan BFS dari simpul 2 untuk mencetak urutan simpul yang dikunjungi.

##### Contoh Program Tree

```
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;

    Node(int nilai) {
        data = nilai;
        kiri = nullptr;
        kanan = nullptr;
    }
};

void inorderTraversal(Node* node) {
    if (node == nullptr)
        return;

    inorderTraversal(node->kiri);
    cout << node->data << " ";
    inorderTraversal(node->kanan);
}

int main() {
    Node* root = new Node(1);
    root->kiri = new Node(2);
    root->kanan = new Node(3);
    root->kiri->kiri = new Node(4);
    root->kiri->kanan = new Node(5);

    cout << "Inorder traversal dari pohon biner:\n";
    inorderTraversal(root);

    return 0;
}
```

##### Penjelasan Program

Program ini mendefinisikan struktur Node yang merepresentasikan simpul dalam sebuah pohon biner. Setiap simpul memiliki nilai data (data) dan dua penunjuk (kiri dan kanan) ke anak kiri dan kanan. Fungsi inorderTraversal melakukan traversal inorder pada pohon, yaitu mengunjungi anak kiri, kemudian simpul saat ini, dan kemudian anak kanan. Program utama membuat sebuah pohon biner sederhana dengan beberapa simpul dan melakukan traversal inorder, mencetak nilai-nilai simpul dalam urutan yang benar. Program ini menunjukkan bagaimana membuat dan menjelajahi struktur pohon biner.

## Referensi

[1] Mulyono, L.T.S. (2009). PERANCANGAN PROGRAM APLIKASI SIMULASI SISTEM KONTROL ELEVATOR MENGGUNAKAN ORDINAL STRUCTURE FUZZY LOGIC (OSFL). (Skripsi Sarjana, Binus University). http://library.binus.ac.id/eColls/eThesisdoc/Bab2HTML/2009100390MTIFBab2/page11.html

[2] Barata, G.S.H., Pangestu, B.B, Lay, E.W. & Alghifari, M. (2022). "Priority Queue". https://www.scribd.com/document/657230171/Makalah-Priority-Queue-revisi

[3] Prestiliano, J. (2007). Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data. Jurnal Teknologi Informasi-Aiti, 4(1), 41-56.

[4] Universitas Hasanuddin. (2022). "Hash Table". https://www.studocu.com/id/document/universitas-hasanuddin/pengolahan-dan-analisis-data/hash-table/40318865

[5] Rahayu, S. (2023). "Algoritma Rekursi". https://janabadra.ac.id/2023/algoritma-rekursi/

[6] Chauhan, S. (2024). "What is Recursion in C++ | Types of Recursion in C++ ( With Examples )". https://www.scholarhat.com/tutorial/cpp/recursion-in-cpp

[7] Triase. (2020). Struktur Data. Medan: Fakultas Saintek UIN SU.

[8] Latifah, F. (2016). Penerapan Algorithma Pohon untuk Operasi Pengolahan dan Penyimpanan Data dalam Teknik Pemrograman (kajian algorithma pohon pada teknik pemrograman). Jurnal Techno Nusa Mandiri, 13(2), 23-32.
# <h1 align="center">Tugas 2 Struktur Data</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## CPMK 2 - SubCPMK 2

### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

#### Jawaban

A. Bubble Sort

Alur dari bubble sort umumnya yaitu:
1. Melakukan perbandingan elemen pertama dengan elemen kedua.
2. Apabila elemen pertama lebih besar, tukar posisinya.
3. Lanjutkan perbandingan dan penukaran antar elemen hingga elemen terakhir.
4. Ulangi proses perbandingan dan penukaran dari awal hingga tidak ada lagi perubahan yang berarti elemen sudah terurut.

Runtime:
a. Best Case: O(n) : Best case tercapai ketika elemen sudah terurut dari awal, sehingga tidak ada pertukaran yang dilakukan.
b. Worst Case: O(n^2) : Worst case terjadi ketika elemen terurut terbalik, sehingga butuh banyak perulangan untuk menukar elemen ke posisi yang seharusnya.

B. Selection Sort

Alur dari selection sort umumnya yaitu:
1. Cari elemen terkecil dari daftar.
2. Tukar elemen terkecil dengan elemen pertama.
3. Ulangi kedua langkah itu untuk elemen seterusnya hingga semua elemen terurut.

Runtime:
a. Best Case: O(n) : Best case tercapai ketika elemen sudah terurut dari awal, sehingga tidak perlu mencari elemen terkecil lagi.
b. Worst Case: O(n^2) : Worst case terjadi ketika elemen terurut terbalik, sehingga butuh banyak perulangan untuk menemukan dan menukar elemen terkecil.

C. Merge Sort

Alur dari merge sort umumnya yaitu:
1. Bagi daftar jadi dua bagian yang sama besar.
2. Lakukan pengurutan secara rekursif pada kedua bagian.
3. Gabungkan kedua bagian yang sudah terurut menjadi satu daftar berurut.

Runtime:
a. Best Case: O(n log n) : Best case tercapai ketika elemen sudah terurut dari awal, sehingga penggabungan dua bagian itu dapat dilakukan dengan cepat.
b. Worst Case: O(n log n) : Worst case terjadi apabila elemen terurut secara terbalik dan penggabungan dua bagian yang sudah terurut tetap membutuhkan waktu O(n log n).

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

#### Jawaban

```
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int arr[] = {5, 2, 4, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, n);

  cout << "Daftar setelah diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
```

Pada program itu, fungsi bubbleSort memiliki dua loop for yang saling bersarang. Looping luar iterasi sebanyak n - 1 kali, sedangkan looping dalam iterasi sebanyak n - i - 1 kali. Pada setiap iterasi, elemen-elemen yang berdekatan dibandingkan dan ditukar posisinya jika elemen yang pertama lebih besar daripada elemen yang kedua. Proses ini diulang sampai semua elemen dalam array terurut.

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

#### Jawaban

```
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool tesAnagram(string str1, string str2) {
  transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
  str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());

  transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
  str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());

  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  return str1 == str2;
}

int main() {
  string str1, str2;

  cout << "Masukkan string satu: ";
  getline(cin, str1);

  cout << "Masukkan string dua: ";
  getline(cin, str2);

  if (tesAnagram(str1, str2)) {
    cout << "\"" << str1 << "\" dan \"" << str2 << "\" anagram." << endl;
  } else {
    cout << "\"" << str1 << "\" dan \"" << str2 << "\" bukan anagram." << endl;
  }

  return 0;
}
```
![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/29934ccf-8ccd-4d36-a845-fd6c242b6833)
![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/d2758e3e-aa12-4d27-9689-bee8d0f74ccb)

### 4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 

#### Jawaban

```
#include <iostream>
#include <algorithm>

using namespace std;

void mergeAndSort(int A[], int sizeA, int B[], int sizeB) {
  for (int i = 0; i < sizeB; ++i) {
    A[sizeA + i] = B[i];
  }

  sort(A, A + sizeA + sizeB);
}

int main() {
  int A[] = {2, 5, 8, 15, 20};
  int sizeA = sizeof(A) / sizeof(A[0]);
  int B[] = {1, 3, 4, 7, 9};
  int sizeB = sizeof(B) / sizeof(B[0]);

  mergeAndSort(A, sizeA, B, sizeB);

  cout << "Array A setelah digabungkan dan diurutkan: ";
  for (int i = 0; i < sizeA + sizeB; ++i) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/bb962ea0-aa48-4680-8ae9-6690e5c01657)

## CPMK 2 - SubCPMK 3

### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

A. Linear Search

Alur dari linear search yaitu:
1. Dimulai dari elemen pertama. Bandingkan elemen yang dicari dengan elemen yang sedang diperiksa.
   - Jika sama, kembalikan posisi elemen yang dicari.
   - Jika tidak sama, lanjut ke elemen berikutnya.
2. Ulangi hal tersebut hingga elemen terakhir diperiksa.
3. Jika elemen yang dicari tidak ditemukan di seluruh data, berarti elemen itu tidak ada.

Runtime:
a. Best Case: O(1) : Best case terjadi ketika elemen yang dicari ditemukan pada elemen pertama.
b. Worst Case: O(n) : Worst case terjadi apabila elemen yang dicari tidak ada dalam data dan seluruh elemen harus diperiksa.

B. Binary Search

Alur dari binary search yaitu:
1. Dimulai dari bagian tengah data. Bandingkan elemen yang dicari dengan elemen tengah.
   - Jika sama, kembalikan posisi elemen yang dicari.
   - Jika lebih kecil, cari di bagian kiri data.
   - Jika lebih besar, cari di bagian kanan data.
2. Ulangi langkah itu hingga elemen ditemukan atau seluruh data telah diperiksa.
3. Jika elemen yang dicari tidak ditemukan, maka elemen itu tidak ada.

Runtime:

a. Best Case: O(1) : Best case Terjadi ketika elemen ditemukan pada elemen tengah.
b. Worst Case: O(log n) : Worst Case terjadi ketika elemen yang dicari tidak ada dalam data dan seluruh data harus diperiksa dengan cara membagi dua berulang kali.

### 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut!

```
#include <iostream>

using namespace std;

bool pencarian_biner(int data[], int jumlah_data, int target) {
  int awal = 0;
  int akhir = jumlah_data - 1;

  while (awal <= akhir) {
    int tengah = (awal + akhir) / 2;

    if (data[tengah] == target) {
      return true;
    } else if (data[tengah] < target) {
      awal = tengah + 1;
    } else {
      akhir = tengah - 1;
    }
  }

  return false;
}

int main() {
  int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int jumlah_data = sizeof(data) / sizeof(data[0]);
  int target = 23;

  if (pencarian_biner(data, jumlah_data, target)) {
    cout << "Elemen " << target << " ditemukan pada indeks " << pencarian_biner(data, jumlah_data, target) << endl;
  } else {
    cout << "Elemen " << target << " tidak ditemukan" << endl;
  }

  return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/ad6728bb-cd16-4010-8876-4db576bbc262)

Pada program ini, fungsi pencarian_biner menampung data array, jumlah elemen, dan elemen yang dicari dan akan mendefinisikan batas awal dan akhir pencarian. Kemudian, ia akan melakukan loop while selama batas belum bertemu yang menghitung indeks tengah dari rentang pencarian dan membandingkan elemen tengah dengan elemen yang dicari. Ada 4 kemungkinan hasil yang akan terjadi,
- Jika sama, elemen ditemukan dan fungsi return true. Jika lebih kecil, perbarui batas awal ke kanan.
- Jika lebih besar, perbarui batas akhir ke kiri.
- Jika loop selesai dan elemen tidak ditemukan, fungsi return false.

Sedangkan fungsi main menyiapkan array data terurut dan elemen yang dicari (23) dan memanggil fungsi pencarian_biner untuk mencari elemen. Hasilnya kemudian akan ditampilkan berdasarkan hasil pencarian (ditemukan atau tidak). Karena disini yang dicari adalah elemen ke 23, yang ternyata ada pada array, maka hasilnya akan menunjukkan bahwa elemen ditemukan pada indeks tertentu yaitu 1.

### 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 


```
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cariKata(const vector<string>& arr, const string& kata) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int left = mid;
        while (left >= 0 && arr[left] == "")
            left--;
        if (left >= 0 && arr[left] == kata)
            return left;

        int right = mid;
        while (right < arr.size() && arr[right] == "")
            right++;
        if (right < arr.size() && arr[right] == kata)
            return right;

        if (arr[mid] == "" || arr[mid] > kata)
            high = left - 1;
        else
            low = right + 1;
    }

    return -1;
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    string kata = "bola";
    int hasil = cariKata(arr, kata);
    if (hasil != -1)
        cout << "Indeks kata \"" << kata << "\" adalah: " << hasil << endl;
    else
        cout << "Kata \"" << kata << "\" tidak ditemukan." << endl;

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/0ab932ba-9615-4aa9-8a0d-9ebaed4ef369)

## CPMK 2 - SubCPMK 4

### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

#### Jawaban

Struct atau structure adalah cara untuk mengelompokkan beberapa variabel terkait ke dalam satu tempat. Variabel-variabel dalam struct dikenal sebagai anggota struct. Struct dapat memungkinkan kita untuk membuat tipe data baru yang bisa disesuaikan dengan keperluan.

```
#include <iostream>

using namespace std;

struct Buku {
  string judul;
  string penulis;
  int tahunTerbit;
  int harga;
};

int main() {
  Buku buku1;

  buku1.judul = "Sherlock Holmes";
  buku1.penulis = "Arthur Conan Doyle";
  buku1.tahunTerbit = 1891;
  buku1.harga = 100000;

  cout << "Judul: " << buku1.judul << endl;
  cout << "Penulis: " << buku1.penulis << endl;
  cout << "Tahun Terbit: " << buku1.tahunTerbit << endl;
  cout << "Harga: " << buku1.harga << endl;

  return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/a8c45bc0-69d8-4de5-91a5-a628d6ccc06b)

## CMPK 2 - SubCPMK 5

### 1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular). 

```
#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void hapusDuplikasi(Node* head) {
    if (head == nullptr)
        return;

    unordered_set<int> terlihat;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (terlihat.find(curr->data) != terlihat.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            terlihat.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    cout << "Linked list sebelum penghapusan duplikasi: ";
    tampilkan(head);

    hapusDuplikasi(head);

    cout << "Linked list setelah penghapusan duplikasi: ";
    tampilkan(head);

    hapusList(head);

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/72bbf201-1a76-468c-9e56-996a0c028fca)

### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list!

```
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void tambahNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusNodeTengah(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        return;
    }
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr;
    tambahNode(head, 1);
    tambahNode(head, 2);
    tambahNode(head, 3);
    tambahNode(head, 4);
    tambahNode(head, 5);

    cout << "Linked list sebelum penghapusan node di tengah: ";
    tampilkan(head);

    Node* nodeTengah = head->next;
    hapusNodeTengah(nodeTengah);

    cout << "Linked list setelah penghapusan node di tengah: ";
    tampilkan(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/58d15f70-3dfd-4365-a080-70a129439d82)

### 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

void tambahNode(Node*& head, char data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool cekPalindrom(Node* head) {
    stack<char> karakterStack;
    Node* temp = head;

    while (temp != nullptr) {
        karakterStack.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr) {
        char karakter = karakterStack.top();
        karakterStack.pop();
        if (temp->data != karakter) {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

int main() {
    Node* head = nullptr;
    tambahNode(head, 'a');
    tambahNode(head, 'b');
    tambahNode(head, 'b');
    tambahNode(head, 'a');

    cout << "Linked list: ";
    tampilkan(head);

    if (cekPalindrom(head)) {
        cout << "Linked list palindrom." << endl;
    } else {
        cout << "Linked list bukan palindrom." << endl;
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/fd701a05-27a5-44bf-b100-17e0e5b138f6)

## CPMK 2 - SubCPMK 6

### 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)!

```
#include <iostream>

using namespace std;

#define MAX_SIZE 5

struct Stack {
    int data[MAX_SIZE];
    int top;

    Stack() {
        top = -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh, push gagal." << endl;
            return;
        }
        top++;
        data[top] = value;
        cout << "Elemen " << value << " berhasil ditambahkan ke stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong, pop gagal." << endl;
            return;
        }
        cout << "Elemen " << data[top] << " dihapus dari stack." << endl;
        top--;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    int getTop() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return -1; // Nilai default jika stack kosong
        }
        return data[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return;
        }
        cout << "Isi stack: ";
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();

    cout << "Top stack: " << stack.getTop() << endl;

    stack.pop();
    stack.display();

    cout << "Top stack: " << stack.getTop() << endl;

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/23bdeaad-9360-42fc-b63b-389ec6658dae)

### 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.

```
#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

void displayStack(stack<int> s) {
    cout << "Isi stack setelah disortir: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Isi stack sebelum disortir: ";
    displayStack(s);

    sortStack(s);

    displayStack(s);

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/5f812dab-b722-4a29-8e06-02b3c0c870e6)

## CPMK 2 - SubCPMK 7

### 1.	Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)!

```
#include <iostream>

using namespace std;

#define MAX_SIZE 5

struct Queue {
    int data[MAX_SIZE];
    int front, rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh, enqueue gagal." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        data[rear] = value;
        cout << "Elemen " << value << " berhasil ditambahkan ke queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong, dequeue gagal." << endl;
            return;
        }
        int removedValue = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Elemen " << removedValue << " dihapus dari queue." << endl;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return -1; // Nilai default jika queue kosong
        }
        return data[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        cout << "Isi queue: ";
        int i = front;
        while (i != rear) {
            cout << data[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << data[rear] << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();

    cout << "Elemen depan queue: " << queue.getFront() << endl;

    queue.dequeue();
    queue.display();

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/af8da016-1474-4228-8992-c1554f311487)

## 2.	Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat. 

```
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Animal {
    string name;
    int time;

    Animal(string n, int t) : name(n), time(t) {}
};

class AnimalShelter {
private:
    queue<Animal> dogs;
    queue<Animal> cats;
    int time;

public:
    AnimalShelter() {
        time = 0;
    }

    void enquee(string name, string type) {
        if (type == "dog") {
            dogs.push(Animal(name, time++));
        } else if (type == "cat") {
            cats.push(Animal(name, time++));
        } else {
            cout << "Hewan yang diterima hanya kucing atau anjing." << endl;
        }
    }

    Animal dequeueAny() {
        if (dogs.empty() && cats.empty()) {
            cout << "Shelter kosong." << endl;
            return Animal("", -1);
        } else if (dogs.empty()) {
            Animal oldestCat = cats.front();
            cats.pop();
            return oldestCat;
        } else if (cats.empty()) {
            Animal oldestDog = dogs.front();
            dogs.pop();
            return oldestDog;
        } else {
            if (dogs.front().time < cats.front().time) {
                Animal oldestDog = dogs.front();
                dogs.pop();
                return oldestDog;
            } else {
                Animal oldestCat = cats.front();
                cats.pop();
                return oldestCat;
            }
        }
    }

    Animal dequeueDog() {
        if (dogs.empty()) {
            cout << "Tidak ada anjing di shelter." << endl;
            return Animal("", -1);
        } else {
            Animal oldestDog = dogs.front();
            dogs.pop();
            return oldestDog;
        }
    }

    Animal dequeueCat() {
        if (cats.empty()) {
            cout << "Tidak ada kucing di shelter." << endl;
            return Animal("", -1);
        } else {
            Animal oldestCat = cats.front();
            cats.pop();
            return oldestCat;
        }
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enquee("Tom", "cat");
    shelter.enquee("Max", "dog");
    shelter.enquee("Luna", "cat");
    shelter.enquee("Buddy", "dog");

    Animal adopted1 = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adopted1.name << " (Jenis: " << ((adopted1.name == "") ? "Tidak ada" : ((adopted1.name == "Tom" || adopted1.name == "Luna") ? "Kucing" : "Anjing")) << ")" << endl;

    Animal adoptedDog = shelter.dequeueDog();
    cout << "Anjing yang diadopsi: " << adoptedDog.name << endl;

    Animal adopted2 = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adopted2.name << " (Jenis: " << ((adopted2.name == "") ? "Tidak ada" : ((adopted2.name == "Max" || adopted2.name == "Buddy") ? "Anjing" : "Kucing")) << ")" << endl;

    return 0;
}
```

![image](https://github.com/rndyyprsty/Teori-Aldat/assets/162487464/874dba3f-4018-434a-ad47-1ba45846d56f)

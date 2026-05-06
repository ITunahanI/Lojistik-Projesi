Proje Adı: Lojistik Firması Hibrit Veri Yapısı Projesi
Kullanılan Yöntemler: Tip B Hash, Zincirleme (Chaining) Çakışma Çözümü, DFS Graf Gezinme

1. RAM Durumu ve Veri Girişleri
Sisteme sırasıyla 101, 201, 305, 408 ve 502 ID'li 5 paket girişi yapılmıştır. Tip B Hash Fonksiyonu H(k)=(k×7)(mod10) olarak belirlenmiştir.

ID: 101 -> Hash: 7

ID: 201 -> Hash: 7 (Çakışma - Zincirlemeye Girdi)

ID: 305 -> Hash: 5

ID: 408 -> Hash: 6

ID: 502 -> Hash: 4

2. Dinamik Yapıların Şematik Pointer Bağlantıları

Plaintext
Hash Table (Temel Dizi Adresi: 0x7FFC2A801000)
--------------------------------------------------------------------------------------
Index [4] -> Adres: 0x55E9A120 (ID: 502) -> NEXT: NULL
Index [5] -> Adres: 0x55E9A1A0 (ID: 305) -> NEXT: NULL
Index [6] -> Adres: 0x55E9A1E0 (ID: 408) -> NEXT: NULL
Index [7] -> Adres: 0x55E9A160 (ID: 201) -> NEXT: Adres: 0x55E9A100 (ID: 101) -> NEXT: NULL
Index [8] -> NULL
Index [9] -> NULL
--------------------------------------------------------------------------------------
* Not: 7 numaralı indekste çakışma (collision) meydana gelmiş olup, LIFO (Son Giren İlk Çıkar) 
  mantığıyla 201 numaralı paketin 'next' pointer'ı 101 numaralı paketi işaret etmektedir.

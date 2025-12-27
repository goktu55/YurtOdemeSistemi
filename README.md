# Yurt Ücreti Ödeme Sistemi (C)

Bu proje, öğrencilerin TC kimlik numaraları ile giriş yaparak yurt tiplerine göre ödeme yapmalarını sağlayan, basit ve etkileşimli bir C programıdır. Program, kullanıcı verilerini doğrular ve ödeme bilgilerini yerel bir dosyada saklar.

## Özellikler

* **TC Kimlik Doğrulama:** 11 haneli ve sadece rakamlardan oluşan TC numarası kontrolü.
* **Mükerrer Ödeme Kontrolü:** `kayit.txt` dosyasını tarayarak aynı TC ile birden fazla ödeme yapılmasını engeller.
* **Dinamik Ücretlendirme:** 6 farklı yurt tipi için farklı fiyatlandırma seçenekleri.
* **Kart Bilgileri Validasyonu:** Kredi kartı numarası (16 hane), SKT (AA/YY) ve CVV (3 hane) için format kontrolleri.
* **Veri Kaydı:** Başarılı ödemelerin ardından TC kimlik numaraları `kayit.txt` dosyasına kaydedilir.

## Kullanılan Teknolojiler

* **Dil:** C
* **Dosyalama:** Standart C Dosya Giriş/Çıkış (`stdio.h`, `FILE`)
* **Kütüphaneler:** `string.h` (metin işlemleri için)

## Nasıl Çalıştırılır?

Projenin bilgisayarınızda çalışması için bir C derleyicisine (GCC, Clang, MSVC vb.) ihtiyacınız vardır.

1.  **Depoyu Klonlayın:**
    ```bash
    git clone [https://github.com/kullaniciadi/yurt-odeme-sistemi.git](https://github.com/kullaniciadi/yurt-odeme-sistemi.git)
    ```
2.  **Klasöre Gidin:**
    ```bash
    cd yurt-odeme-sistemi
    ```
3.  **Derleyin:**
    ```bash
    gcc main.c -o yurt_sistemi
    ```
4.  **Çalıştırın:**
    ```bash
    ./yurt_sistemi
    ```
    
## Lisans
Bu proje eğitim amaçlıdır ve geliştirilmeye açıktır.

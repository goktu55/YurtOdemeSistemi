#include <stdio.h>
#include <string.h>

void tcdogrulama(char *tc) 
{
    int gecerli_tc;

    do 
    {
        gecerli_tc = 1;
        printf("TC kimlik numaranızı giriniz: ");
        scanf("%11s", tc);
        if (strlen(tc) != 11) 
        {
            gecerli_tc = 0;
            printf("TC kimlik numarası 11 haneli olmalıdır.\n");
        }
        else 
        {
            for (int i = 0; i < 11; i++) 
            {
                if (tc[i] < '0' || tc[i] > '9') 
                {
                    gecerli_tc = 0;
                    printf("TC kimlik numarası sadece rakamlardan oluşmalıdır.\n");
                    break;
                }
            }
        }
    } while (!gecerli_tc);    
}


int main() 
{
    char tc[12];
    char kart_kayitli[10];
    char kredi_karti[17];
    int gecerli_kredi_karti;
    char son_kullanma_tarihi[6];
    int gecerli_kullanma_tarihi;
    char cvv[4];
    int gecerli_cvv;
    int yurt_tipi;
    int gecerli_yurt_tipi;
    int yurt_ucreti;
    char isim[50];
    int gecerli_kart;
    char kayitli_tc[12];

    printf("================== YURT ÜCRETİ ÖDEME SİSTEMİ ====================\n");

    tcdogrulama(tc);

    FILE *fp = fopen("kayit.txt", "r");
    if (fp) {
        if (fscanf(fp, "%11s", kayitli_tc) == 1 && strcmp(tc, kayitli_tc) == 0) {
            fclose(fp);
            printf("Yurt ücretiniz zaten ödenmiştir.\n");
            return 0;
        }
        fclose(fp);
    }

    gecerli_yurt_tipi = 0;
    while (!gecerli_yurt_tipi)
    {
        printf("Yurt tipinizi seçiniz. 1-6: ");
        if (scanf("%d", &yurt_tipi) != 1)
        {
            printf("Geçerli bir sayı giriniz.\n");
            continue;
        }
        
        switch (yurt_tipi) 
        {
            case 1:
                yurt_ucreti = 750;
                gecerli_yurt_tipi = 1;
                break;
            case 2:
                yurt_ucreti = 850;
                gecerli_yurt_tipi = 1;
                break;
            case 3:
                yurt_ucreti = 950;
                gecerli_yurt_tipi = 1;
                break;
            case 4:
                yurt_ucreti = 1050;
                gecerli_yurt_tipi = 1;
                break;
            case 5:
                yurt_ucreti = 1150;
                gecerli_yurt_tipi = 1;
                break;
            case 6:
                yurt_ucreti = 1200;
                gecerli_yurt_tipi = 1;
                break;
            default:
                printf("Geçerli bir yurt tipi seçiniz.\n");
        }
    }
    
    printf("Yurt ücreti: %d TL\n", yurt_ucreti);

    gecerli_kart = 0;
    while (!gecerli_kart)
    {
        printf("Kayıtlı kredi kartınız var mı? e/h : ");
        scanf(" %s", kart_kayitli);
        if ((kart_kayitli[0] == 'E' || kart_kayitli[0] == 'e') || (kart_kayitli[0] == 'H' || kart_kayitli[0] == 'h'))
        {
            gecerli_kart = 1;
        }
        else
        {
            printf("Geçerli bir cevap giriniz. e/h \n");
        }
    }
            
    if (kart_kayitli[0] == 'H' || kart_kayitli[0] == 'h') 
    {
        do 
        {
            gecerli_kredi_karti = 1;
            printf("Kredi kartı numaranızı giriniz: ");
            scanf("%16s", kredi_karti);
        
            if (strlen(kredi_karti) != 16) 
            {
                gecerli_kredi_karti = 0;
                printf("Kredi kartı numarası 16 haneli olmalıdır.\n");
            } 
            else 
            {
                for (int i = 0; i < 16; i++) 
                {
                    if (kredi_karti[i] < '0' || kredi_karti[i] > '9') 
                    {
                        gecerli_kredi_karti = 0;
                        printf("Kredi kartı numarası rakamlardan oluşmalıdır.\n");
                        break;
                    }
                }
            }
        } while (!gecerli_kredi_karti);

        do 
        {
            gecerli_kullanma_tarihi = 1;
            printf("Son kullanma tarihini giriniz (AA/YY): ");
            scanf("%5s", son_kullanma_tarihi);
            if (strlen(son_kullanma_tarihi) != 5 || son_kullanma_tarihi[2] != '/') 
            {
                gecerli_kullanma_tarihi = 0;
                printf("Son kullanma tarihi formatı AA/YY olmalıdır.\n");
            }
            else 
            {
                for (int i = 0; i < 5; i++) 
                {
                    if (i != 2 && (son_kullanma_tarihi[i] < '0' || son_kullanma_tarihi[i] > '9')) 
                    {
                        gecerli_kullanma_tarihi = 0;
                        printf("Son kullanma tarihi rakamlardan oluşmalıdır.\n");
                        break;
                    }
                }
            }
        } while (!gecerli_kullanma_tarihi);

        do 
        {
            gecerli_cvv = 1;
            printf("CVV kodunu giriniz: ");
            scanf("%3s", cvv);
            if (strlen(cvv) != 3) 
            {
                gecerli_cvv = 0;
                printf("CVV kodu 3 haneli olmalıdır.\n");
            } 
            else 
            {
                for (int i = 0; i < 3; i++) 
                {
                    if (cvv[i] < '0' || cvv[i] > '9') 
                    {
                        gecerli_cvv = 0;
                        printf("CVV kodu rakamlardan oluşmalıdır.\n");
                        break;
                    }
                }
            }
        } while (!gecerli_cvv);
        char kart_kaydet;
        printf("Kredi kartınızı kaydetmek ister misiniz? e/h ");
        scanf(" %c", &kart_kaydet);
        if (kart_kaydet == 'E' || kart_kaydet == 'e')
        {
            printf("Kredi kartının adını giriniz: ");
            scanf("%49s", isim);
            printf("%s adındaki kredi kartınız kaydedildi.\n", isim);
        }
        printf("Seçili kredi kartı ile ödeme yapılıyor...\n");
        printf("Ödeme işlemi tamamlandı.\n");
        FILE *fp_kayit = fopen("kayit.txt", "a");
        fprintf(fp_kayit, "%s\n", tc);
        fclose(fp_kayit);
    }
    else
    {
        printf("Kayıtlı kredi kartı ile ödeme yapılıyor...\n");
        printf("Ödeme işlemi tamamlandı.\n");
        FILE *fp_kayit = fopen("kayit.txt", "a");
        fprintf(fp_kayit, "%s\n", tc);
        fclose(fp_kayit);
    }
    return 0;
}
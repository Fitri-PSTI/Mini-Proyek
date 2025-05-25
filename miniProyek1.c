#include <stdio.h>
#include <time.h>
#include <string.h>

// Fungsi untuk menghitung countdown ke waktu target
void hitungCountdown(int tahun, int bulan, int tanggal, int jam, int menit) {
    struct tm waktuSekarang; //struct untuk pngelompokan variabel
    struct tm waktuTarget;

    time_t now = time(NULL); // karena menggunkan #include <time.h> jadi menggunkan time_t untuk menyimpan waktu
    waktuSekarang = *localtime(&now);

    // Set waktu target dari input
    waktuTarget.tm_year = tahun - 1900;
    waktuTarget.tm_mon = bulan - 1;
    waktuTarget.tm_mday = tanggal;
    waktuTarget.tm_hour = jam;
    waktuTarget.tm_min = menit;
    waktuTarget.tm_sec = 0;

    time_t targetTime = mktime(&waktuTarget);

    double selisihDetik = difftime(targetTime, now);

    if (selisihDetik <= 0) {
        printf("WADUH GAWAT WAKTUNYA UDAH LEWAT⛔!\n");
        return;
    }

    int totalMenit = selisihDetik / 60;
    int hari = totalMenit / (24 * 60);
    int sisaMenit = totalMenit % (24 * 60);
    int jamSisa = sisaMenit / 60;
    int menitAkhir = sisaMenit % 60;

    printf("🕒 SEMANGAT PROKERANNYA 🥰 TINGGAL: %d hari, %d jam, %d menit lagi.\n", hari, jamSisa, menitAkhir);
}

int main() {
    int tahun, bulan, tanggal, jam, menit;
    int jumlah;
    char reminderList[10][100];

    printf("Masukkan jumlah reminder: ");
    scanf("%d", &jumlah);
    getchar(); // Untuk menghapus newline setelah scanf

    for (int i = 0; i < jumlah; i++) {
        printf("\nReminder ke-%d\n", i + 1);
        printf("Isi reminder: ");
        fgets(reminderList[i], sizeof(reminderList[i]), stdin); // fgets: untuk membca input dari string
        reminderList[i][strcspn(reminderList[i], "\n")] = '\0'; // hapus newline dan mengitung jumla karakter string

        printf("Masukkan tahun target: ");
        scanf("%d", &tahun);
        printf("Masukkan bulan target (1-12): ");
        scanf("%d", &bulan);
        printf("Masukkan tanggal target (1-31): ");
        scanf("%d", &tanggal);
        printf("Masukkan jam target (0-23): ");
        scanf("%d", &jam);
        printf("Masukkan menit target (0-59): ");
        scanf("%d", &menit);
        getchar(); // hapus newline

        printf("\n🔔 Reminder: %s\n", reminderList[i]);
        hitungCountdown(tahun, bulan, tanggal, jam, menit);
    }
}
int calcolaPopolazione(int popolazioneIniziale, int percentualeNascite, int migrazione) {
    if (percentualeNascite < -100 || percentualeNascite > 100) return -1;
    int incremento = popolazioneIniziale * percentualeNascite / 100.0;
    int nuovaPopolazione = popolazioneIniziale + incremento + migrazione;
    if (nuovaPopolazione < 0) return 0;
    return nuovaPopolazione;
}

int calcolaPopolazioneAnni(int anni, int popolazioneIniziale, int percentualeNascite, int migrazione) {
    int popolazioneCorrente = popolazioneIniziale;
    for (int i = 0; i < anni; i++) {
        popolazioneCorrente = calcolaPopolazione(popolazioneCorrente, percentualeNascite, migrazione);
        if (popolazioneCorrente <= 0) break;
    }
    return popolazioneCorrente;
}
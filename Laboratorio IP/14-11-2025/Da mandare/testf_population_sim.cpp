int calcola_popolazione(unsigned int popolazioneIniziale, int percentualeNascite, int migrazione) {
    if (percentualeNascite < -100 || percentualeNascite > 100) return -1;
    int incremento = popolazioneIniziale * percentualeNascite / 100.0;
    int nuovaPopolazione = popolazioneIniziale + incremento + migrazione;
    if (nuovaPopolazione < 0) return 0;
    return nuovaPopolazione;
}
void main()
{
    // Tempo de contagem regressiva (em segundos)
    setglobalvar("continuecountdown", 15);

    // Mensagem na tela
    log("=== CONTINUE? Aperte START! ===");

    // Som de alerta (se você tiver um som configurado no data/sounds/)
    playsample("data/sounds/alert.wav", 0);

    // Você pode também mudar a cor do fundo ou aplicar fade
    // Exemplo: fade para preto antes de mostrar a tela
    fadeout(0, 0, 0, 30); // R, G, B, velocidade
}

# Especificação da Implementação

> [!CAUTION]
> - Você <ins>**não pode utilizar ferramentas de IA para escrever esta
>   especificação**</ins>

## Integrantes da dupla

- **Aluno 1 - Nome**: Guilherme de Sousa Cirumbolo
- **Aluno 1 - Cartão UFRGS**: 330049

- **Aluno 2 - Nome**: Pedro Marhofer Alles
- **Aluno 2 - Cartão UFRGS**: 326188

## Detalhes do que será implementado

- **Título do trabalho**: Zebra Hunter
- **Parágrafo curto descrevendo o que será implementado**: Jogo de Caca onde o jogador esta num Safari e usa uma Sniper para matar o animal.

## Especificação visual

### Vídeo - Link

- [Demo Video](demo-files/DemoVideo.mp4)

### Vídeo - Timestamp



- **Timestamp inicial**: 0:20
- **Timestamp final**: 0:50

### Imagens


- [Zebra](demo-files/animal.png)  
- [Ambiente/Mapa](demo-files/map.png)  
- [Arma](demo-files/sniper.png)

## Especificação textual

### Malhas poligonais complexas
O jogo utilizará modelos geométricos carregados a partir de arquivos externos para representar objetos com formas detalhadas. Como visto em `animal.png` e `sniper.png`, a zebra e a arma de caça são malhas de triângulos complexas que definem silhuetas orgânicas e mecânicas, indo além de formas geométricas básicas.

### Transformações geométricas controladas pelo usuário
O usuário terá controle direto sobre as transformações de rotação da Sniper através do movimento do mouse, permitindo a mira. Além disso, o deslocamento pelo cenário (translação) será controlado pelas teclas de navegação, alterando a posição do jogador no mundo 3D.

### Diferentes tipos de câmeras
Serão implementados dois sistemas de visualização: uma câmera de primeira pessoa (estilo *FPS*) que acompanha a mira da arma para o gameplay, e uma câmera livre (estilo *fly-through*) que permite navegar por todo o mapa do Safari mostrado em `map.png` para fins de exploração e teste.

### Instâncias de objetos
Para compor a fauna do Safari sem sobrecarregar a memória, o modelo da zebra será renderizado utilizando instâncias. Isso significa que o mesmo conjunto de vértices será reaproveitado para desenhar vários animais em posições e orientações distintas, cada um com sua própria *Model Matrix*.

### Testes de intersecção
A mecânica principal de tiro utilizará testes de intersecção entre uma semirreta (lançada a partir da mira) e o volume da zebra. Também serão implementados testes de colisão do tipo AABB (caixas envolventes) para impedir que o jogador atravesse elementos do cenário, como árvores e rochas.

### Modelos de Iluminação em todos os objetos
Todos os elementos visuais utilizarão o modelo de iluminação de Phong. Isso permitirá simular a luz solar incidente sobre a savana, gerando reflexos especulares na lente da sniper e sombras difusas na pelagem da zebra, conferindo volume aos modelos.

### Mapeamento de texturas em todos os objetos
Todos os objetos terão suas cores definidas por imagens. Utilizaremos no mínimo três texturas distintas: o padrão de listras da zebra, o material metálico da arma e a textura de vegetação/solo para o terreno do mapa, aplicadas sem distorções artificiais.

### Movimentação com curva Bézier cúbica
A trajetória de deslocamento das zebras pelo cenário não será retilínea. Elas seguirão caminhos suaves definidos por curvas de Bézier cúbicas, garantindo que o movimento de fuga ou patrulha dos animais pareça natural e fluido dentro do Safari.

### Animações baseadas no tempo ($\Delta t$)
Todas as atualizações de posição, rotação e lógica de jogo serão calculadas em função do tempo decorrido ($\Delta t$). Isso garante que a velocidade da zebra e a sensibilidade da mira sejam consistentes, independentemente da taxa de quadros (FPS) alcançada pelo computador.

## Limitações esperadas

- **Animação Esquelética**: Embora os animais se movam pelo cenário via curvas de Bézier, as malhas podem não apresentar movimento articulado (patas dobrando), limitando-se a translações e rotações do modelo rígido.
- **Vegetação Estática**: As árvores e arbustos vistos no vídeo de referência podem não sofrer deformações por vento, sendo tratados como objetos rígidos para focar nos requisitos de iluminação e textura.
- **Complexidade do Terreno**: O mapa pode apresentar uma topografia simplificada em comparação a vídeos cinematográficos, priorizando a performance e a aplicação correta das texturas de solo.

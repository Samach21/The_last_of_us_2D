uniform sampler2D texture;

void main() {
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    if (pixel.a < 1.0) {
        gl_FragColor = pixel * vec4(1.0, 1.0, 1.0, 0.0);
    }
    else {
        gl_FragColor = pixel * vec4(1.0, 1.0, 1.0, 1.0);
    }
}
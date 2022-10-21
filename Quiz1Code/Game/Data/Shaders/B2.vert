attribute vec2 a_Position;
attribute vec4 a_Color;

uniform vec2 u_Scale;
uniform float u_Offset;

varying vec4 v_Color;

void main()
{
	vec2 scale = vec2(u_Scale);
	float angle = 0.0 / 180.0 * 3.14;
	vec2 offset = vec2(u_Offset,0);

	vec2 pos = a_Position;

	// Scale.
	pos *= scale;
	
	// Rotate.
	float newX = cos(angle)*pos.x + -sin(angle)*pos.y;
	float newY = sin(angle)*pos.x + cos(angle)*pos.y;
	pos = vec2(newX, newY);
	
	// Translate.
	pos += offset;

	gl_Position = vec4( pos, 0, 1 );

	v_Color = a_Color;
}

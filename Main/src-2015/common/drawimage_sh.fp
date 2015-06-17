// SL 2012-02-08

uniform sampler2D u_Image;

uniform sampler2D u_Mask;
uniform int       u_UseMask;
uniform int       u_RevertMask;
uniform vec2      u_MaskSize;
uniform vec2      u_MaskPos;

varying vec2      v_TexCoord;

uniform vec2      u_ImageSize;
uniform vec4      u_UVWH;

void main()
{
  vec2 uv         = ((v_TexCoord  * u_UVWH.zw) + u_UVWH.xy) / u_ImageSize.xy;
  vec4 clr        = texture2D( u_Image, uv );

  if (u_UseMask != 0) {
    vec2 uv_mask = ((vec2(v_TexCoord.x,1.0-v_TexCoord.y)* u_UVWH.zw) + u_UVWH.xy - u_MaskPos.xy) / u_MaskSize.xy + vec2(0.5);
	uv_mask = vec2(uv_mask.x,1.0-uv_mask.y);
    vec4 mask = texture2D( u_Mask, uv_mask );
	if (u_RevertMask != 0) {
	  mask = vec4(1.0) - mask;
	}
	clr.xyz = mask.xyz * clr.xyz;
  }

  gl_FragColor    = clr;


}


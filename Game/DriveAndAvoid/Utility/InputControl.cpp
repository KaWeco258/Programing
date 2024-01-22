#include "InputControl.h"
#include "DxLib.h"

//�ÓI�����o�ϐ���`
bool InputControl::now_button[16] = {};
bool InputControl::old_button[16] = {};
float InputControl::trigger[2] = {};
Vector2D InputControl::stick[2] = {};

//���͋@�\�F�X�V����
void InputControl::Update()
{
	//XInput�R���g���[���[�̓��͒l���擾����
	XINPUT_STATE input_state = {};
	GetJoypadInputState(DX_INPUT_PAD1, &input_state);

	//�{�^���̓��͒l�̍X�V
	for (int i = 0; i < 16; i++)
	{
		old_button[i] = now_button[i];
		now_button[i] = (bool)input_state.Buttons[i];
	}

	//�g���K�[���͒l�̍X�V�i0.0f~1.0f�ɔ͈͂𐧌�����j
	trigger[0] = (float)input_state.LeftTrigger / (float)UCHAR_MAX;
	trigger[1] = (float)input_state.RightTrigger / (float)UCHAR_MAX;
}
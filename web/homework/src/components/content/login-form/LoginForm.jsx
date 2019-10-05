import React, { Component } from 'react';
import { Form, Input, Icon, Checkbox, Button } from 'antd';
import styles from './LoginForm.scss';

class _LoginForm extends Component {

    constructor(props) {
        super(props);

        this.handleSubmit = this.handleSubmit.bind(this);
    }

    handleSubmit = e => {
        e.preventDefault();

        this.props.form.validateFields((err, values) => {
            if (!err) {
                console.log('Received value of form: ', values);
            }
        })
    }

    render() {
        const { getFieldDecorator } = this.props.form;
        return (
            <Form onSubmit={ null } className='login-form'>
                <Form.Item>
                    <Input
                        prefix={ <Icon type='user' style={{ color: 'rgba(0, 0, 0, .25)'}} />}
                        placeholder="Username"
                        style={ styles.input }
                    />
                </Form.Item>
                <Form.Item>
                    <Input
                        prefix={ <Icon type='lock' style={{ color: 'rgba(0, 0, 0, .25)'}} />}
                        type="password"
                        placeholder="Password"
                        style={ styles.input }
                    />
                </Form.Item>
                <Form.Item>
                    <Checkbox>Remember me</Checkbox>
                    <a className='login-form-forgot' href="">
                        Forgot password
                    </a>
                    <Button
                        type='primary'
                        htmlType='submit'
                        className='login-form-button'
                        onClick={ this.handleSubmit }
                    >
                        Log in
                    </Button>
                    Or <a href="">register now!</a>
                </Form.Item>
            </Form>
        )
    }
}

const LoginForm = Form.create()(_LoginForm)

export default LoginForm;